/*
 * Copyright (c) 2018 Next Limit S.L.
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
*/

#pragma once

#if defined(_WIN32)
// Pull in minimal Windows headers
#if ! defined(NOMINMAX)
#define NOMINMAX
#endif
#if ! defined(WIN32_LEAN_AND_MEAN)
#define WIN32_LEAN_AND_MEAN
#endif
#endif

#define GLEW_STATIC

#include "../../../Common_3/ThirdParty/OpenSource/GLEW/GL/glew.h"

#include "../../ThirdParty/OpenSource/TinySTL/vector.h"

#define GL_DEFINE_HANDLE(object) typedef struct object##_T* object;

GL_DEFINE_HANDLE(GlContext)
GL_DEFINE_HANDLE(GlContextView)
