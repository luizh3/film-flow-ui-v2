#pragma once

#include <QList>
#include <algorithm>

namespace CardFetchHelper {

template<typename TCard,
         typename TDomain,
         typename BeginRemoveFn,
         typename EndRemoveFn,
         typename DataChangedFn,
         typename ApplyFn>
void updateCards(QList<TCard *> &allCards,
                 QList<TCard *> &fetchingCards,
                 const QList<TDomain *> &domainItems,
                 BeginRemoveFn &&beginRemove,
                 EndRemoveFn &&endRemove,
                 DataChangedFn &&dataChanged,
                 ApplyFn &&applyData)
{
    const int updateCount = std::min(fetchingCards.size(), domainItems.size());

    for (int i = 0; i < updateCount; ++i) {
        applyData(fetchingCards[i], domainItems[i]);
    }

    const int excess = fetchingCards.size() - domainItems.size();

    if (excess > 0) {
        const int start = allCards.size() - excess;

        beginRemove(start, allCards.size() - 1);

        for (int i = fetchingCards.size() - 1; i >= domainItems.size(); --i) {
            auto *card = fetchingCards[i];
            allCards.removeAll(card);
            fetchingCards.removeAll(card);
            delete card;
        }

        endRemove();
    }

    dataChanged(allCards.size() - fetchingCards.size(), allCards.size() - 1);
}

template<typename TCard, typename BeginInsertFn, typename EndInsertFn, typename CreateFn>
void appendFetchingCards(QList<TCard *> &allCards,
                         QList<TCard *> &fetchingCards,
                         int count,
                         BeginInsertFn &&beginInsert,
                         EndInsertFn &&endInsert,
                         CreateFn &&createCard)
{
    const int start = allCards.size();
    const int end = start + count - 1;

    beginInsert(start, end);

    fetchingCards.clear();
    fetchingCards.reserve(count);

    std::generate_n(std::back_inserter(fetchingCards), count, createCard);

    allCards.append(fetchingCards);

    endInsert();
}

} // namespace CardFetchHelper
