#include "CefViewResourceProvider.h"

#include <Common/CefViewCoreLog.h>

CefViewResourceProvider::CefViewResourceProvider(
  CefViewBrowserClientDelegateInterface::WeakPtr delegate)
  : delegate_(delegate)
{
}

bool
CefViewResourceProvider::OnRequest(scoped_refptr<CefResourceManager::Request> request)
{
  CEF_REQUIRE_IO_THREAD();

  auto delegate = delegate_.lock();
  if (!delegate) {
    return false;
  }

  // Get request information
  auto browser = request->browser();
  auto frame = request->frame();
  auto cef_request = request->request();

  if (!browser || !frame || !cef_request) {
    return false;
  }

  // Get the URL
  auto url = cef_request->GetURL();

  // Forward the request to the delegate
  // The delegate will notify the application layer
  delegate->processResourceRequest(browser, frame, cef_request);

  // Return false to allow the request to continue normally
  // If you want to handle the request yourself, return true and call request->Continue() or request->Stop()
  return false;
}

