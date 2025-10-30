//
//  CefViewResourceProvider.h
//  CefViewCore
//
//  Created for custom resource request handling
//

#ifndef CefViewResourceProvider_h
#define CefViewResourceProvider_h
#pragma once

#include <CefViewCoreGlobal.h>
#include <CefViewBrowserClientDelegate.h>

/// <summary>
/// Custom resource provider that forwards resource requests to the delegate
/// </summary>
class CefViewResourceProvider
  : public CefBaseRefCounted
  , public CefResourceManager::Provider
{
  IMPLEMENT_REFCOUNTING(CefViewResourceProvider);

public:
  /// <summary>
  /// Constructor
  /// </summary>
  /// <param name="delegate">The client delegate to forward requests to</param>
  CefViewResourceProvider(CefViewBrowserClientDelegateInterface::WeakPtr delegate);

  /// <summary>
  /// Called to handle a resource request
  /// </summary>
  virtual bool OnRequest(scoped_refptr<CefResourceManager::Request> request) override;

private:
  /// <summary>
  /// Weak pointer to the client delegate
  /// </summary>
  CefViewBrowserClientDelegateInterface::WeakPtr delegate_;
};

#endif

