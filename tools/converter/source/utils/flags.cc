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

#include "tools/converter/source/utils/flags.h"

namespace TNN_CONVERTER {

DEFINE_bool(h, false, help_message);

DEFINE_string(mp, "", tf_path_message);

DEFINE_string(od, "", output_dir_message);

DEFINE_string(mt, "", model_type_message);

DEFINE_string(sp, "", save_path_message);

DEFINE_bool(half, false, half_message);

}  // namespace TNN_CONVERTER
