#include "sectioncontroller.h"

#include <model/result/searchmoviesresult.h>

#include <manager/applicationmanager.h>

#include <network/endpoint/filmflowsectionendpoint.h>
#include <network/response/response.h>

#include <helper/taskrunhelper.h>

SectionController::SectionController()
    : _filmFlowSectionEndpoint{new FilmFlowSectionEndpoint(ApplicationManager::instance().session())}
{}

SectionController::~SectionController() = default;

QFuture<SearchMoviesResult *> SectionController::find(const SectionRequest &request)
{
    return TaskRunHelper::promiseAsync<SearchMoviesResult, Response>(
        _filmFlowSectionEndpoint->find(request));
}

void SectionController::cancel()
{
    _filmFlowSectionEndpoint->cancel();
}
