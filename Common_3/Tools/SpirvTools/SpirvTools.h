/*
 * Copyright (c) 2018 Confetti Interactive Inc.
 * 
 * This file is part of The-Forge
 * (see https://github.com/ConfettiFX/The-Forge).
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

#include <stdint.h>
#if defined _WIN32 || defined __CYGWIN__ || defined __MINGW32__
  #ifdef API_EXPORT
    #ifdef __GNUC__
      #define SPIRV_INTERFACE __attribute__ ((dllexport))
    #else
      #define SPIRV_INTERFACE __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #else
    #ifdef __GNUC__
      #define SPIRV_INTERFACE __attribute__ ((dllimport))
    #else
      #define SPIRV_INTERFACE __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #endif
#else
  #if __GNUC__ >= 4
    #define SPIRV_INTERFACE __attribute__ ((visibility ("default")))
  #else
    #define SPIRV_INTERFACE
  #endif
#endif

#if defined( _WIN32 )
#define CALLTYPE __cdecl
#else
#define CALLTYPE 
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// spirv cross
// This is a C API DLL
// We do this to sperate the stl code out of our codebase
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct SPIRV_Type
{
   // Resources are identified with their SPIR-V ID.
   // This is the ID of the OpVariable.
   uint32_t id;

   // The type ID of the variable which includes arrays and all type modifications.
   // This type ID is not suitable for parsing OpMemberDecoration of a struct and other decorations in general
   // since these modifications typically happen on the base_type_id.
   uint32_t type_id;

   // The base type of the declared resource.
   // This type is the base type which ignores pointers and arrays of the type_id.
   // This is mostly useful to parse decorations of the underlying type.
   // base_type_id can also be obtained with get_type(get_type(type_id).self).
   uint32_t base_type_id;
};

enum SPIRV_Resource_Type
{
   SPIRV_TYPE_STAGE_INPUTS = 0,
   SPIRV_TYPE_STAGE_OUTPUTS,
   SPIRV_TYPE_UNIFORM_BUFFERS,
   SPIRV_TYPE_STORAGE_BUFFERS,
   SPIRV_TYPE_IMAGES,
   SPIRV_TYPE_STORAGE_IMAGES,
   SPIRV_TYPE_SAMPLERS,
   SPIRV_TYPE_PUSH_CONSTANT,
   SPIRV_TYPE_SUBPASS_INPUTS,
#if defined(OPENGL)
   SPIRV_TYPE_SAMPLED_IMAGES,
#endif
   SPIRV_TYPE_COUNT
};

struct SPIRV_Resource
{
   // Spirv data type
   SPIRV_Type SPIRV_code;

   // resource Type
   SPIRV_Resource_Type type;

   // If the resouce was used in the shader
   bool is_used;
   
   // The resouce set if it has one
   uint32_t set;
   
   // The resource binding location
   uint32_t binding;

   // The size of the resouce. This will be the descriptor array size for textures
   uint32_t size;

   // The declared name (OpName) of the resource.
   // For Buffer blocks, the name actually reflects the externally
   // visible Block name.
   const char* name;

   // name size
   uint32_t name_size;
};

struct SPIRV_Variable
{
   // Spirv data type
   uint32_t SPIRV_type_id;

   // parents SPIRV code
   SPIRV_Type parent_SPIRV_code;

   // parents resource index
   uint32_t parent_index;

   // If the data was used
   bool is_used;

   // The offset of the Variable.
   uint32_t offset;

   // The size of the Variable.
   uint32_t size;

   // Variable name
   const char* name;

   // name size
   uint32_t name_size;
};

struct CrossCompiler
{
   // this points to the internal compiler class
   void* pCompiler;
   
   // resources
   SPIRV_Resource* pShaderResouces;
   uint32_t ShaderResourceCount;
   
   // uniforms
   SPIRV_Variable* pUniformVariables;
   uint32_t UniformVariablesCount;

   char* pEntryPoint;
   uint32_t EntryPointSize;
};

SPIRV_INTERFACE  void CALLTYPE CreateCrossCompiler(const uint32_t* SpirvBinary, uint32_t BinarySize, CrossCompiler* outCompiler);
SPIRV_INTERFACE  void CALLTYPE DestroyCrossCompiler(CrossCompiler* compiler);

SPIRV_INTERFACE  void CALLTYPE ReflectEntryPoint(CrossCompiler* compiler);

SPIRV_INTERFACE  void CALLTYPE ReflectShaderResources(CrossCompiler* compiler);
SPIRV_INTERFACE  void CALLTYPE ReflectShaderVariables(CrossCompiler* compiler);

SPIRV_INTERFACE  void CALLTYPE ReflectComputeShaderWorkGroupSize(CrossCompiler* compiler, uint32_t* pSizeX, uint32_t* pSizeY, uint32_t* pSizeZ);
SPIRV_INTERFACE  void CALLTYPE ReflectHullShaderControlPoint(CrossCompiler* pCompiler, uint32_t* pSizeX);
