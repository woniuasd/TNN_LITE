// Tencent is pleased to support the open source community by making TNN available.
//
// Copyright (C) 2020 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the BSD 3-Clause License (the "License"); you may not use this file except
// in compliance with the License. You may obtain a copy of the License at
//
// https://opensource.org/licenses/BSD-3-Clause
//
// Unless required by applicable law or agreed to in writing, software distributed
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

#include "onnx_op_converter.h"
#include "onnx_utility.h"

DECLARE_OP_CONVERTER_WITH_FUNC(ScatterElements,
                               virtual std::vector<std::string> GetValidInputNames(NodeProto &node, OnnxNetInfo &net_info););

string OnnxOpConverterScatterElements::TNNOpType(NodeProto& node, OnnxNetInfo& net_info) {
    return "ScatterElements";
}

string OnnxOpConverterScatterElements::TNNLayerParam(NodeProto& node, OnnxNetInfo& net_info) {
    const std::string &onnx_op = node.op_type();
    ostringstream layer_param;

    int axis = 0;
    int op   = 0;

    if (node_has_attr(node, "axis")) {
        axis = get_node_attr_i(node, "axis");
    }
    if (node_has_attr(node, "op")) {
        op = get_node_attr_i(node, "op");
    }

    layer_param << axis << " " << op << " ";

    return layer_param.str();
}

std::vector<std::string> OnnxOpConverterScatterElements::GetValidInputNames(NodeProto &node, OnnxNetInfo &net_info) {
    return {node.input(0), node.input(1), node.input(2)};
}

bool OnnxOpConverterScatterElements::HasLayerResource(NodeProto &node, OnnxNetInfo &net_info) {
    return false;
};

int OnnxOpConverterScatterElements::WriteTNNModel(Serializer* net_writer, NodeProto& node, OnnxNetInfo& net_info) {
    return 0;
}

REGISTER_OP_CONVERTER(ScatterElements, ScatterElements);
