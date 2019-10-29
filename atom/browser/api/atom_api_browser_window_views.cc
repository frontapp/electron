// Copyright (c) 2018 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "atom/browser/api/atom_api_browser_window.h"

#include "atom/browser/native_window_views.h"
#include "atom/common/draggable_region.h"

namespace atom {

namespace api {

void BrowserWindow::UpdateDraggableRegions(
    content::RenderFrameHost* rfh,
    const std::vector<DraggableRegion>& regions) {
  LOG(INFO) << "BrowserWindow::UpdateDraggableRegions regions.size(): "
            << regions.size();
  for (const DraggableRegion& region : regions) {
    LOG(INFO) << "x: " << region.bounds.x() << " y: " << region.bounds.y()
              << " right: " << region.bounds.right()
              << " bottom: " << region.bounds.bottom()
              << " draggable: " << region.draggable;
  }
  if (window_->has_frame())
    return;
  static_cast<NativeWindowViews*>(window_.get())
      ->UpdateDraggableRegions(DraggableRegionsToSkRegion(regions));
}

}  // namespace api

}  // namespace atom
