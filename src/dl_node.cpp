//*****************************************************************************
// Copyright 2020 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//*****************************************************************************
#include "dl_node.hpp"

#include <spdlog/spdlog.h>

#include "prediction_service_utils.hpp"

namespace ovms {

Status DLNode::execute() {
    // Start inference asynchronously
    return StatusCode::OK;
}

Status DLNode::fetchResults(BlobMap& outputs) {
    /*
        for each blob in inferrequest {
            outputs[blob.name] = blob
        }

        SPDLOG_INFO("DLNode::fetchResults (Node name {}): blob with name [{}] has been prepared", getName(), blob.name);
    */

    // Fake output for now
    InferenceEngine::SizeVector shape{1, 1000};
    InferenceEngine::TensorDesc description{InferenceEngine::Precision::I8, shape, InferenceEngine::Layout::ANY};
    outputs["resnet_output"] = InferenceEngine::make_shared_blob<int8_t>(description);
    return StatusCode::OK;
}

}  // namespace ovms
