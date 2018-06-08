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

#include "glcorearbcmd.h"

void glCmdSubmitv(GlCmd* pCmd, size_t n) {
	GlCmd* pCmdLast = pCmd + n;
	for (; pCmd != pCmdLast; ++pCmd) {
		GlCmdType sType = *(GlCmdType *)pCmd;
		switch (sType) {
		case GL_STRUCTURE_TYPE_COMMAND_CullFace: {
			GlCmdCullFace* pCC = (GlCmdCullFace*)pCmd;
			glCullFace(pCC->mMode);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_FrontFace: {
			GlCmdFrontFace* pCC = (GlCmdFrontFace*)pCmd;
			glFrontFace(pCC->mMode);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Hint: {
			GlCmdHint* pCC = (GlCmdHint*)pCmd;
			glHint(pCC->mTarget, pCC->mMode);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_LineWidth: {
			GlCmdLineWidth* pCC = (GlCmdLineWidth*)pCmd;
			glLineWidth(pCC->mWidth);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_PointSize: {
			GlCmdPointSize* pCC = (GlCmdPointSize*)pCmd;
			glPointSize(pCC->mSize);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_PolygonMode: {
			GlCmdPolygonMode* pCC = (GlCmdPolygonMode*)pCmd;
			glPolygonMode(pCC->mFace, pCC->mMode);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Scissor: {
			GlCmdScissor* pCC = (GlCmdScissor*)pCmd;
			glScissor(pCC->mX, pCC->mY, pCC->mWidth, pCC->mHeight);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TexParameterf: {
			GlCmdTexParameterf* pCC = (GlCmdTexParameterf*)pCmd;
			glTexParameterf(pCC->mTarget, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TexParameterfv: {
			GlCmdTexParameterfv* pCC = (GlCmdTexParameterfv*)pCmd;
			glTexParameterfv(pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TexParameteri: {
			GlCmdTexParameteri* pCC = (GlCmdTexParameteri*)pCmd;
			glTexParameteri(pCC->mTarget, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TexParameteriv: {
			GlCmdTexParameteriv* pCC = (GlCmdTexParameteriv*)pCmd;
			glTexParameteriv(pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TexImage1D: {
			GlCmdTexImage1D* pCC = (GlCmdTexImage1D*)pCmd;
			glTexImage1D(pCC->mTarget, pCC->mLevel, pCC->mInternalformat, pCC->mWidth, pCC->mBorder, pCC->mFormat, pCC->mType, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TexImage2D: {
			GlCmdTexImage2D* pCC = (GlCmdTexImage2D*)pCmd;
			glTexImage2D(pCC->mTarget, pCC->mLevel, pCC->mInternalformat, pCC->mWidth, pCC->mHeight, pCC->mBorder, pCC->mFormat, pCC->mType, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DrawBuffer: {
			GlCmdDrawBuffer* pCC = (GlCmdDrawBuffer*)pCmd;
			glDrawBuffer(pCC->mBuf);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Clear: {
			GlCmdClear* pCC = (GlCmdClear*)pCmd;
			glClear(pCC->mMask);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ClearColor: {
			GlCmdClearColor* pCC = (GlCmdClearColor*)pCmd;
			glClearColor(pCC->mRed, pCC->mGreen, pCC->mBlue, pCC->mAlpha);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ClearStencil: {
			GlCmdClearStencil* pCC = (GlCmdClearStencil*)pCmd;
			glClearStencil(pCC->mS);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ClearDepth: {
			GlCmdClearDepth* pCC = (GlCmdClearDepth*)pCmd;
			glClearDepth(pCC->mDepth);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_StencilMask: {
			GlCmdStencilMask* pCC = (GlCmdStencilMask*)pCmd;
			glStencilMask(pCC->mMask);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ColorMask: {
			GlCmdColorMask* pCC = (GlCmdColorMask*)pCmd;
			glColorMask(pCC->mRed, pCC->mGreen, pCC->mBlue, pCC->mAlpha);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DepthMask: {
			GlCmdDepthMask* pCC = (GlCmdDepthMask*)pCmd;
			glDepthMask(pCC->mFlag);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Disable: {
			GlCmdDisable* pCC = (GlCmdDisable*)pCmd;
			glDisable(pCC->mCap);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Enable: {
			GlCmdEnable* pCC = (GlCmdEnable*)pCmd;
			glEnable(pCC->mCap);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Finish: {
			GlCmdFinish* pCC = (GlCmdFinish*)pCmd;
			glFinish();
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Flush: {
			GlCmdFlush* pCC = (GlCmdFlush*)pCmd;
			glFlush();
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BlendFunc: {
			GlCmdBlendFunc* pCC = (GlCmdBlendFunc*)pCmd;
			glBlendFunc(pCC->mSfactor, pCC->mDfactor);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_LogicOp: {
			GlCmdLogicOp* pCC = (GlCmdLogicOp*)pCmd;
			glLogicOp(pCC->mOpcode);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_StencilFunc: {
			GlCmdStencilFunc* pCC = (GlCmdStencilFunc*)pCmd;
			glStencilFunc(pCC->mFunc, pCC->mRef, pCC->mMask);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_StencilOp: {
			GlCmdStencilOp* pCC = (GlCmdStencilOp*)pCmd;
			glStencilOp(pCC->mFail, pCC->mZfail, pCC->mZpass);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DepthFunc: {
			GlCmdDepthFunc* pCC = (GlCmdDepthFunc*)pCmd;
			glDepthFunc(pCC->mFunc);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_PixelStoref: {
			GlCmdPixelStoref* pCC = (GlCmdPixelStoref*)pCmd;
			glPixelStoref(pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_PixelStorei: {
			GlCmdPixelStorei* pCC = (GlCmdPixelStorei*)pCmd;
			glPixelStorei(pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ReadBuffer: {
			GlCmdReadBuffer* pCC = (GlCmdReadBuffer*)pCmd;
			glReadBuffer(pCC->mSrc);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ReadPixels: {
			GlCmdReadPixels* pCC = (GlCmdReadPixels*)pCmd;
			glReadPixels(pCC->mX, pCC->mY, pCC->mWidth, pCC->mHeight, pCC->mFormat, pCC->mType, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetBooleanv: {
			GlCmdGetBooleanv* pCC = (GlCmdGetBooleanv*)pCmd;
			glGetBooleanv(pCC->mPname, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetDoublev: {
			GlCmdGetDoublev* pCC = (GlCmdGetDoublev*)pCmd;
			glGetDoublev(pCC->mPname, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetError: {
			GlCmdGetError* pCC = (GlCmdGetError*)pCmd;
			glGetError();
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetFloatv: {
			GlCmdGetFloatv* pCC = (GlCmdGetFloatv*)pCmd;
			glGetFloatv(pCC->mPname, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetIntegerv: {
			GlCmdGetIntegerv* pCC = (GlCmdGetIntegerv*)pCmd;
			glGetIntegerv(pCC->mPname, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetString: {
			GlCmdGetString* pCC = (GlCmdGetString*)pCmd;
			glGetString(pCC->mName);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetTexImage: {
			GlCmdGetTexImage* pCC = (GlCmdGetTexImage*)pCmd;
			glGetTexImage(pCC->mTarget, pCC->mLevel, pCC->mFormat, pCC->mType, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetTexParameterfv: {
			GlCmdGetTexParameterfv* pCC = (GlCmdGetTexParameterfv*)pCmd;
			glGetTexParameterfv(pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetTexParameteriv: {
			GlCmdGetTexParameteriv* pCC = (GlCmdGetTexParameteriv*)pCmd;
			glGetTexParameteriv(pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetTexLevelParameterfv: {
			GlCmdGetTexLevelParameterfv* pCC = (GlCmdGetTexLevelParameterfv*)pCmd;
			glGetTexLevelParameterfv(pCC->mTarget, pCC->mLevel, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetTexLevelParameteriv: {
			GlCmdGetTexLevelParameteriv* pCC = (GlCmdGetTexLevelParameteriv*)pCmd;
			glGetTexLevelParameteriv(pCC->mTarget, pCC->mLevel, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_IsEnabled: {
			GlCmdIsEnabled* pCC = (GlCmdIsEnabled*)pCmd;
			glIsEnabled(pCC->mCap);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DepthRange: {
			GlCmdDepthRange* pCC = (GlCmdDepthRange*)pCmd;
			glDepthRange(pCC->mN, pCC->mF);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Viewport: {
			GlCmdViewport* pCC = (GlCmdViewport*)pCmd;
			glViewport(pCC->mX, pCC->mY, pCC->mWidth, pCC->mHeight);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DrawArrays: {
			GlCmdDrawArrays* pCC = (GlCmdDrawArrays*)pCmd;
			glDrawArrays(pCC->mMode, pCC->mFirst, pCC->mCount);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DrawElements: {
			GlCmdDrawElements* pCC = (GlCmdDrawElements*)pCmd;
			glDrawElements(pCC->mMode, pCC->mCount, pCC->mType, pCC->mIndices);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetPointerv: {
			GlCmdGetPointerv* pCC = (GlCmdGetPointerv*)pCmd;
			glGetPointerv(pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_PolygonOffset: {
			GlCmdPolygonOffset* pCC = (GlCmdPolygonOffset*)pCmd;
			glPolygonOffset(pCC->mFactor, pCC->mUnits);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CopyTexImage1D: {
			GlCmdCopyTexImage1D* pCC = (GlCmdCopyTexImage1D*)pCmd;
			glCopyTexImage1D(pCC->mTarget, pCC->mLevel, pCC->mInternalformat, pCC->mX, pCC->mY, pCC->mWidth, pCC->mBorder);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CopyTexImage2D: {
			GlCmdCopyTexImage2D* pCC = (GlCmdCopyTexImage2D*)pCmd;
			glCopyTexImage2D(pCC->mTarget, pCC->mLevel, pCC->mInternalformat, pCC->mX, pCC->mY, pCC->mWidth, pCC->mHeight, pCC->mBorder);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CopyTexSubImage1D: {
			GlCmdCopyTexSubImage1D* pCC = (GlCmdCopyTexSubImage1D*)pCmd;
			glCopyTexSubImage1D(pCC->mTarget, pCC->mLevel, pCC->mXoffset, pCC->mX, pCC->mY, pCC->mWidth);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CopyTexSubImage2D: {
			GlCmdCopyTexSubImage2D* pCC = (GlCmdCopyTexSubImage2D*)pCmd;
			glCopyTexSubImage2D(pCC->mTarget, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mX, pCC->mY, pCC->mWidth, pCC->mHeight);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TexSubImage1D: {
			GlCmdTexSubImage1D* pCC = (GlCmdTexSubImage1D*)pCmd;
			glTexSubImage1D(pCC->mTarget, pCC->mLevel, pCC->mXoffset, pCC->mWidth, pCC->mFormat, pCC->mType, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TexSubImage2D: {
			GlCmdTexSubImage2D* pCC = (GlCmdTexSubImage2D*)pCmd;
			glTexSubImage2D(pCC->mTarget, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mWidth, pCC->mHeight, pCC->mFormat, pCC->mType, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BindTexture: {
			GlCmdBindTexture* pCC = (GlCmdBindTexture*)pCmd;
			glBindTexture(pCC->mTarget, pCC->mTexture);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DeleteTextures: {
			GlCmdDeleteTextures* pCC = (GlCmdDeleteTextures*)pCmd;
			glDeleteTextures(pCC->mN, pCC->mTextures);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GenTextures: {
			GlCmdGenTextures* pCC = (GlCmdGenTextures*)pCmd;
			glGenTextures(pCC->mN, pCC->mTextures);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_IsTexture: {
			GlCmdIsTexture* pCC = (GlCmdIsTexture*)pCmd;
			glIsTexture(pCC->mTexture);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DrawRangeElements: {
			GlCmdDrawRangeElements* pCC = (GlCmdDrawRangeElements*)pCmd;
			glDrawRangeElements(pCC->mMode, pCC->mStart, pCC->mEnd, pCC->mCount, pCC->mType, pCC->mIndices);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TexImage3D: {
			GlCmdTexImage3D* pCC = (GlCmdTexImage3D*)pCmd;
			glTexImage3D(pCC->mTarget, pCC->mLevel, pCC->mInternalformat, pCC->mWidth, pCC->mHeight, pCC->mDepth, pCC->mBorder, pCC->mFormat, pCC->mType, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TexSubImage3D: {
			GlCmdTexSubImage3D* pCC = (GlCmdTexSubImage3D*)pCmd;
			glTexSubImage3D(pCC->mTarget, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mZoffset, pCC->mWidth, pCC->mHeight, pCC->mDepth, pCC->mFormat, pCC->mType, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CopyTexSubImage3D: {
			GlCmdCopyTexSubImage3D* pCC = (GlCmdCopyTexSubImage3D*)pCmd;
			glCopyTexSubImage3D(pCC->mTarget, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mZoffset, pCC->mX, pCC->mY, pCC->mWidth, pCC->mHeight);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ActiveTexture: {
			GlCmdActiveTexture* pCC = (GlCmdActiveTexture*)pCmd;
			glActiveTexture(pCC->mTexture);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_SampleCoverage: {
			GlCmdSampleCoverage* pCC = (GlCmdSampleCoverage*)pCmd;
			glSampleCoverage(pCC->mValue, pCC->mInvert);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CompressedTexImage3D: {
			GlCmdCompressedTexImage3D* pCC = (GlCmdCompressedTexImage3D*)pCmd;
			glCompressedTexImage3D(pCC->mTarget, pCC->mLevel, pCC->mInternalformat, pCC->mWidth, pCC->mHeight, pCC->mDepth, pCC->mBorder, pCC->mImagesize, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CompressedTexImage2D: {
			GlCmdCompressedTexImage2D* pCC = (GlCmdCompressedTexImage2D*)pCmd;
			glCompressedTexImage2D(pCC->mTarget, pCC->mLevel, pCC->mInternalformat, pCC->mWidth, pCC->mHeight, pCC->mBorder, pCC->mImagesize, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CompressedTexImage1D: {
			GlCmdCompressedTexImage1D* pCC = (GlCmdCompressedTexImage1D*)pCmd;
			glCompressedTexImage1D(pCC->mTarget, pCC->mLevel, pCC->mInternalformat, pCC->mWidth, pCC->mBorder, pCC->mImagesize, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CompressedTexSubImage3D: {
			GlCmdCompressedTexSubImage3D* pCC = (GlCmdCompressedTexSubImage3D*)pCmd;
			glCompressedTexSubImage3D(pCC->mTarget, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mZoffset, pCC->mWidth, pCC->mHeight, pCC->mDepth, pCC->mFormat, pCC->mImagesize, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CompressedTexSubImage2D: {
			GlCmdCompressedTexSubImage2D* pCC = (GlCmdCompressedTexSubImage2D*)pCmd;
			glCompressedTexSubImage2D(pCC->mTarget, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mWidth, pCC->mHeight, pCC->mFormat, pCC->mImagesize, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CompressedTexSubImage1D: {
			GlCmdCompressedTexSubImage1D* pCC = (GlCmdCompressedTexSubImage1D*)pCmd;
			glCompressedTexSubImage1D(pCC->mTarget, pCC->mLevel, pCC->mXoffset, pCC->mWidth, pCC->mFormat, pCC->mImagesize, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetCompressedTexImage: {
			GlCmdGetCompressedTexImage* pCC = (GlCmdGetCompressedTexImage*)pCmd;
			glGetCompressedTexImage(pCC->mTarget, pCC->mLevel, pCC->mImg);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BlendFuncSeparate: {
			GlCmdBlendFuncSeparate* pCC = (GlCmdBlendFuncSeparate*)pCmd;
			glBlendFuncSeparate(pCC->mSfactorrgb, pCC->mDfactorrgb, pCC->mSfactoralpha, pCC->mDfactoralpha);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiDrawArrays: {
			GlCmdMultiDrawArrays* pCC = (GlCmdMultiDrawArrays*)pCmd;
			glMultiDrawArrays(pCC->mMode, pCC->mFirst, pCC->mCount, pCC->mDrawcount);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiDrawElements: {
			GlCmdMultiDrawElements* pCC = (GlCmdMultiDrawElements*)pCmd;
			glMultiDrawElements(pCC->mMode, pCC->mCount, pCC->mType, pCC->mIndices, pCC->mDrawcount);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_PointParameterf: {
			GlCmdPointParameterf* pCC = (GlCmdPointParameterf*)pCmd;
			glPointParameterf(pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_PointParameterfv: {
			GlCmdPointParameterfv* pCC = (GlCmdPointParameterfv*)pCmd;
			glPointParameterfv(pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_PointParameteri: {
			GlCmdPointParameteri* pCC = (GlCmdPointParameteri*)pCmd;
			glPointParameteri(pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_PointParameteriv: {
			GlCmdPointParameteriv* pCC = (GlCmdPointParameteriv*)pCmd;
			glPointParameteriv(pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BlendColor: {
			GlCmdBlendColor* pCC = (GlCmdBlendColor*)pCmd;
			glBlendColor(pCC->mRed, pCC->mGreen, pCC->mBlue, pCC->mAlpha);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BlendEquation: {
			GlCmdBlendEquation* pCC = (GlCmdBlendEquation*)pCmd;
			glBlendEquation(pCC->mMode);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GenQueries: {
			GlCmdGenQueries* pCC = (GlCmdGenQueries*)pCmd;
			glGenQueries(pCC->mN, pCC->mIds);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DeleteQueries: {
			GlCmdDeleteQueries* pCC = (GlCmdDeleteQueries*)pCmd;
			glDeleteQueries(pCC->mN, pCC->mIds);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_IsQuery: {
			GlCmdIsQuery* pCC = (GlCmdIsQuery*)pCmd;
			glIsQuery(pCC->mId);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BeginQuery: {
			GlCmdBeginQuery* pCC = (GlCmdBeginQuery*)pCmd;
			glBeginQuery(pCC->mTarget, pCC->mId);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_EndQuery: {
			GlCmdEndQuery* pCC = (GlCmdEndQuery*)pCmd;
			glEndQuery(pCC->mTarget);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetQueryiv: {
			GlCmdGetQueryiv* pCC = (GlCmdGetQueryiv*)pCmd;
			glGetQueryiv(pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetQueryObjectiv: {
			GlCmdGetQueryObjectiv* pCC = (GlCmdGetQueryObjectiv*)pCmd;
			glGetQueryObjectiv(pCC->mId, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetQueryObjectuiv: {
			GlCmdGetQueryObjectuiv* pCC = (GlCmdGetQueryObjectuiv*)pCmd;
			glGetQueryObjectuiv(pCC->mId, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BindBuffer: {
			GlCmdBindBuffer* pCC = (GlCmdBindBuffer*)pCmd;
			glBindBuffer(pCC->mTarget, pCC->mBuffer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DeleteBuffers: {
			GlCmdDeleteBuffers* pCC = (GlCmdDeleteBuffers*)pCmd;
			glDeleteBuffers(pCC->mN, pCC->mBuffers);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GenBuffers: {
			GlCmdGenBuffers* pCC = (GlCmdGenBuffers*)pCmd;
			glGenBuffers(pCC->mN, pCC->mBuffers);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_IsBuffer: {
			GlCmdIsBuffer* pCC = (GlCmdIsBuffer*)pCmd;
			glIsBuffer(pCC->mBuffer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BufferData: {
			GlCmdBufferData* pCC = (GlCmdBufferData*)pCmd;
			glBufferData(pCC->mTarget, pCC->mSize, pCC->mData, pCC->mUsage);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BufferSubData: {
			GlCmdBufferSubData* pCC = (GlCmdBufferSubData*)pCmd;
			glBufferSubData(pCC->mTarget, pCC->mOffset, pCC->mSize, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetBufferSubData: {
			GlCmdGetBufferSubData* pCC = (GlCmdGetBufferSubData*)pCmd;
			glGetBufferSubData(pCC->mTarget, pCC->mOffset, pCC->mSize, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MapBuffer: {
			GlCmdMapBuffer* pCC = (GlCmdMapBuffer*)pCmd;
			glMapBuffer(pCC->mTarget, pCC->mAccess);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_UnmapBuffer: {
			GlCmdUnmapBuffer* pCC = (GlCmdUnmapBuffer*)pCmd;
			glUnmapBuffer(pCC->mTarget);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetBufferParameteriv: {
			GlCmdGetBufferParameteriv* pCC = (GlCmdGetBufferParameteriv*)pCmd;
			glGetBufferParameteriv(pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetBufferPointerv: {
			GlCmdGetBufferPointerv* pCC = (GlCmdGetBufferPointerv*)pCmd;
			glGetBufferPointerv(pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BlendEquationSeparate: {
			GlCmdBlendEquationSeparate* pCC = (GlCmdBlendEquationSeparate*)pCmd;
			glBlendEquationSeparate(pCC->mModergb, pCC->mModealpha);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DrawBuffers: {
			GlCmdDrawBuffers* pCC = (GlCmdDrawBuffers*)pCmd;
			glDrawBuffers(pCC->mN, pCC->mBufs);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_StencilOpSeparate: {
			GlCmdStencilOpSeparate* pCC = (GlCmdStencilOpSeparate*)pCmd;
			glStencilOpSeparate(pCC->mFace, pCC->mSfail, pCC->mDpfail, pCC->mDppass);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_StencilFuncSeparate: {
			GlCmdStencilFuncSeparate* pCC = (GlCmdStencilFuncSeparate*)pCmd;
			glStencilFuncSeparate(pCC->mFace, pCC->mFunc, pCC->mRef, pCC->mMask);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_StencilMaskSeparate: {
			GlCmdStencilMaskSeparate* pCC = (GlCmdStencilMaskSeparate*)pCmd;
			glStencilMaskSeparate(pCC->mFace, pCC->mMask);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_AttachShader: {
			GlCmdAttachShader* pCC = (GlCmdAttachShader*)pCmd;
			glAttachShader(pCC->mProgram, pCC->mShader);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BindAttribLocation: {
			GlCmdBindAttribLocation* pCC = (GlCmdBindAttribLocation*)pCmd;
			glBindAttribLocation(pCC->mProgram, pCC->mIndex, pCC->mName);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CompileShader: {
			GlCmdCompileShader* pCC = (GlCmdCompileShader*)pCmd;
			glCompileShader(pCC->mShader);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CreateProgram: {
			GlCmdCreateProgram* pCC = (GlCmdCreateProgram*)pCmd;
			glCreateProgram();
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CreateShader: {
			GlCmdCreateShader* pCC = (GlCmdCreateShader*)pCmd;
			glCreateShader(pCC->mType);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DeleteProgram: {
			GlCmdDeleteProgram* pCC = (GlCmdDeleteProgram*)pCmd;
			glDeleteProgram(pCC->mProgram);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DeleteShader: {
			GlCmdDeleteShader* pCC = (GlCmdDeleteShader*)pCmd;
			glDeleteShader(pCC->mShader);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DetachShader: {
			GlCmdDetachShader* pCC = (GlCmdDetachShader*)pCmd;
			glDetachShader(pCC->mProgram, pCC->mShader);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DisableVertexAttribArray: {
			GlCmdDisableVertexAttribArray* pCC = (GlCmdDisableVertexAttribArray*)pCmd;
			glDisableVertexAttribArray(pCC->mIndex);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_EnableVertexAttribArray: {
			GlCmdEnableVertexAttribArray* pCC = (GlCmdEnableVertexAttribArray*)pCmd;
			glEnableVertexAttribArray(pCC->mIndex);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetActiveAttrib: {
			GlCmdGetActiveAttrib* pCC = (GlCmdGetActiveAttrib*)pCmd;
			glGetActiveAttrib(pCC->mProgram, pCC->mIndex, pCC->mBufsize, pCC->mLength, pCC->mSize, pCC->mType, pCC->mName);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetActiveUniform: {
			GlCmdGetActiveUniform* pCC = (GlCmdGetActiveUniform*)pCmd;
			glGetActiveUniform(pCC->mProgram, pCC->mIndex, pCC->mBufsize, pCC->mLength, pCC->mSize, pCC->mType, pCC->mName);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetAttachedShaders: {
			GlCmdGetAttachedShaders* pCC = (GlCmdGetAttachedShaders*)pCmd;
			glGetAttachedShaders(pCC->mProgram, pCC->mMaxcount, pCC->mCount, pCC->mShaders);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetAttribLocation: {
			GlCmdGetAttribLocation* pCC = (GlCmdGetAttribLocation*)pCmd;
			glGetAttribLocation(pCC->mProgram, pCC->mName);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetProgramiv: {
			GlCmdGetProgramiv* pCC = (GlCmdGetProgramiv*)pCmd;
			glGetProgramiv(pCC->mProgram, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetProgramInfoLog: {
			GlCmdGetProgramInfoLog* pCC = (GlCmdGetProgramInfoLog*)pCmd;
			glGetProgramInfoLog(pCC->mProgram, pCC->mBufsize, pCC->mLength, pCC->mInfolog);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetShaderiv: {
			GlCmdGetShaderiv* pCC = (GlCmdGetShaderiv*)pCmd;
			glGetShaderiv(pCC->mShader, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetShaderInfoLog: {
			GlCmdGetShaderInfoLog* pCC = (GlCmdGetShaderInfoLog*)pCmd;
			glGetShaderInfoLog(pCC->mShader, pCC->mBufsize, pCC->mLength, pCC->mInfolog);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetShaderSource: {
			GlCmdGetShaderSource* pCC = (GlCmdGetShaderSource*)pCmd;
			glGetShaderSource(pCC->mShader, pCC->mBufsize, pCC->mLength, pCC->mSource);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetUniformLocation: {
			GlCmdGetUniformLocation* pCC = (GlCmdGetUniformLocation*)pCmd;
			glGetUniformLocation(pCC->mProgram, pCC->mName);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetUniformfv: {
			GlCmdGetUniformfv* pCC = (GlCmdGetUniformfv*)pCmd;
			glGetUniformfv(pCC->mProgram, pCC->mLocation, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetUniformiv: {
			GlCmdGetUniformiv* pCC = (GlCmdGetUniformiv*)pCmd;
			glGetUniformiv(pCC->mProgram, pCC->mLocation, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetVertexAttribdv: {
			GlCmdGetVertexAttribdv* pCC = (GlCmdGetVertexAttribdv*)pCmd;
			glGetVertexAttribdv(pCC->mIndex, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetVertexAttribfv: {
			GlCmdGetVertexAttribfv* pCC = (GlCmdGetVertexAttribfv*)pCmd;
			glGetVertexAttribfv(pCC->mIndex, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetVertexAttribiv: {
			GlCmdGetVertexAttribiv* pCC = (GlCmdGetVertexAttribiv*)pCmd;
			glGetVertexAttribiv(pCC->mIndex, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetVertexAttribPointerv: {
			GlCmdGetVertexAttribPointerv* pCC = (GlCmdGetVertexAttribPointerv*)pCmd;
			glGetVertexAttribPointerv(pCC->mIndex, pCC->mPname, pCC->mPointer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_IsProgram: {
			GlCmdIsProgram* pCC = (GlCmdIsProgram*)pCmd;
			glIsProgram(pCC->mProgram);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_IsShader: {
			GlCmdIsShader* pCC = (GlCmdIsShader*)pCmd;
			glIsShader(pCC->mShader);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_LinkProgram: {
			GlCmdLinkProgram* pCC = (GlCmdLinkProgram*)pCmd;
			glLinkProgram(pCC->mProgram);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ShaderSource: {
			GlCmdShaderSource* pCC = (GlCmdShaderSource*)pCmd;
			glShaderSource(pCC->mShader, pCC->mCount, pCC->mString, pCC->mLength);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_UseProgram: {
			GlCmdUseProgram* pCC = (GlCmdUseProgram*)pCmd;
			glUseProgram(pCC->mProgram);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform1f: {
			GlCmdUniform1f* pCC = (GlCmdUniform1f*)pCmd;
			glUniform1f(pCC->mLocation, pCC->mV0);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform2f: {
			GlCmdUniform2f* pCC = (GlCmdUniform2f*)pCmd;
			glUniform2f(pCC->mLocation, pCC->mV0, pCC->mV1);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform3f: {
			GlCmdUniform3f* pCC = (GlCmdUniform3f*)pCmd;
			glUniform3f(pCC->mLocation, pCC->mV0, pCC->mV1, pCC->mV2);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform4f: {
			GlCmdUniform4f* pCC = (GlCmdUniform4f*)pCmd;
			glUniform4f(pCC->mLocation, pCC->mV0, pCC->mV1, pCC->mV2, pCC->mV3);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform1i: {
			GlCmdUniform1i* pCC = (GlCmdUniform1i*)pCmd;
			glUniform1i(pCC->mLocation, pCC->mV0);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform2i: {
			GlCmdUniform2i* pCC = (GlCmdUniform2i*)pCmd;
			glUniform2i(pCC->mLocation, pCC->mV0, pCC->mV1);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform3i: {
			GlCmdUniform3i* pCC = (GlCmdUniform3i*)pCmd;
			glUniform3i(pCC->mLocation, pCC->mV0, pCC->mV1, pCC->mV2);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform4i: {
			GlCmdUniform4i* pCC = (GlCmdUniform4i*)pCmd;
			glUniform4i(pCC->mLocation, pCC->mV0, pCC->mV1, pCC->mV2, pCC->mV3);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform1fv: {
			GlCmdUniform1fv* pCC = (GlCmdUniform1fv*)pCmd;
			glUniform1fv(pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform2fv: {
			GlCmdUniform2fv* pCC = (GlCmdUniform2fv*)pCmd;
			glUniform2fv(pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform3fv: {
			GlCmdUniform3fv* pCC = (GlCmdUniform3fv*)pCmd;
			glUniform3fv(pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform4fv: {
			GlCmdUniform4fv* pCC = (GlCmdUniform4fv*)pCmd;
			glUniform4fv(pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform1iv: {
			GlCmdUniform1iv* pCC = (GlCmdUniform1iv*)pCmd;
			glUniform1iv(pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform2iv: {
			GlCmdUniform2iv* pCC = (GlCmdUniform2iv*)pCmd;
			glUniform2iv(pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform3iv: {
			GlCmdUniform3iv* pCC = (GlCmdUniform3iv*)pCmd;
			glUniform3iv(pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform4iv: {
			GlCmdUniform4iv* pCC = (GlCmdUniform4iv*)pCmd;
			glUniform4iv(pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_UniformMatrix2fv: {
			GlCmdUniformMatrix2fv* pCC = (GlCmdUniformMatrix2fv*)pCmd;
			glUniformMatrix2fv(pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_UniformMatrix3fv: {
			GlCmdUniformMatrix3fv* pCC = (GlCmdUniformMatrix3fv*)pCmd;
			glUniformMatrix3fv(pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_UniformMatrix4fv: {
			GlCmdUniformMatrix4fv* pCC = (GlCmdUniformMatrix4fv*)pCmd;
			glUniformMatrix4fv(pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ValidateProgram: {
			GlCmdValidateProgram* pCC = (GlCmdValidateProgram*)pCmd;
			glValidateProgram(pCC->mProgram);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib1d: {
			GlCmdVertexAttrib1d* pCC = (GlCmdVertexAttrib1d*)pCmd;
			glVertexAttrib1d(pCC->mIndex, pCC->mX);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib1dv: {
			GlCmdVertexAttrib1dv* pCC = (GlCmdVertexAttrib1dv*)pCmd;
			glVertexAttrib1dv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib1f: {
			GlCmdVertexAttrib1f* pCC = (GlCmdVertexAttrib1f*)pCmd;
			glVertexAttrib1f(pCC->mIndex, pCC->mX);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib1fv: {
			GlCmdVertexAttrib1fv* pCC = (GlCmdVertexAttrib1fv*)pCmd;
			glVertexAttrib1fv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib1s: {
			GlCmdVertexAttrib1s* pCC = (GlCmdVertexAttrib1s*)pCmd;
			glVertexAttrib1s(pCC->mIndex, pCC->mX);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib1sv: {
			GlCmdVertexAttrib1sv* pCC = (GlCmdVertexAttrib1sv*)pCmd;
			glVertexAttrib1sv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib2d: {
			GlCmdVertexAttrib2d* pCC = (GlCmdVertexAttrib2d*)pCmd;
			glVertexAttrib2d(pCC->mIndex, pCC->mX, pCC->mY);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib2dv: {
			GlCmdVertexAttrib2dv* pCC = (GlCmdVertexAttrib2dv*)pCmd;
			glVertexAttrib2dv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib2f: {
			GlCmdVertexAttrib2f* pCC = (GlCmdVertexAttrib2f*)pCmd;
			glVertexAttrib2f(pCC->mIndex, pCC->mX, pCC->mY);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib2fv: {
			GlCmdVertexAttrib2fv* pCC = (GlCmdVertexAttrib2fv*)pCmd;
			glVertexAttrib2fv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib2s: {
			GlCmdVertexAttrib2s* pCC = (GlCmdVertexAttrib2s*)pCmd;
			glVertexAttrib2s(pCC->mIndex, pCC->mX, pCC->mY);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib2sv: {
			GlCmdVertexAttrib2sv* pCC = (GlCmdVertexAttrib2sv*)pCmd;
			glVertexAttrib2sv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib3d: {
			GlCmdVertexAttrib3d* pCC = (GlCmdVertexAttrib3d*)pCmd;
			glVertexAttrib3d(pCC->mIndex, pCC->mX, pCC->mY, pCC->mZ);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib3dv: {
			GlCmdVertexAttrib3dv* pCC = (GlCmdVertexAttrib3dv*)pCmd;
			glVertexAttrib3dv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib3f: {
			GlCmdVertexAttrib3f* pCC = (GlCmdVertexAttrib3f*)pCmd;
			glVertexAttrib3f(pCC->mIndex, pCC->mX, pCC->mY, pCC->mZ);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib3fv: {
			GlCmdVertexAttrib3fv* pCC = (GlCmdVertexAttrib3fv*)pCmd;
			glVertexAttrib3fv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib3s: {
			GlCmdVertexAttrib3s* pCC = (GlCmdVertexAttrib3s*)pCmd;
			glVertexAttrib3s(pCC->mIndex, pCC->mX, pCC->mY, pCC->mZ);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib3sv: {
			GlCmdVertexAttrib3sv* pCC = (GlCmdVertexAttrib3sv*)pCmd;
			glVertexAttrib3sv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib4Nbv: {
			GlCmdVertexAttrib4Nbv* pCC = (GlCmdVertexAttrib4Nbv*)pCmd;
			glVertexAttrib4Nbv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib4Niv: {
			GlCmdVertexAttrib4Niv* pCC = (GlCmdVertexAttrib4Niv*)pCmd;
			glVertexAttrib4Niv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib4Nsv: {
			GlCmdVertexAttrib4Nsv* pCC = (GlCmdVertexAttrib4Nsv*)pCmd;
			glVertexAttrib4Nsv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib4Nub: {
			GlCmdVertexAttrib4Nub* pCC = (GlCmdVertexAttrib4Nub*)pCmd;
			glVertexAttrib4Nub(pCC->mIndex, pCC->mX, pCC->mY, pCC->mZ, pCC->mW);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib4Nubv: {
			GlCmdVertexAttrib4Nubv* pCC = (GlCmdVertexAttrib4Nubv*)pCmd;
			glVertexAttrib4Nubv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib4Nuiv: {
			GlCmdVertexAttrib4Nuiv* pCC = (GlCmdVertexAttrib4Nuiv*)pCmd;
			glVertexAttrib4Nuiv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib4Nusv: {
			GlCmdVertexAttrib4Nusv* pCC = (GlCmdVertexAttrib4Nusv*)pCmd;
			glVertexAttrib4Nusv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib4bv: {
			GlCmdVertexAttrib4bv* pCC = (GlCmdVertexAttrib4bv*)pCmd;
			glVertexAttrib4bv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib4d: {
			GlCmdVertexAttrib4d* pCC = (GlCmdVertexAttrib4d*)pCmd;
			glVertexAttrib4d(pCC->mIndex, pCC->mX, pCC->mY, pCC->mZ, pCC->mW);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib4dv: {
			GlCmdVertexAttrib4dv* pCC = (GlCmdVertexAttrib4dv*)pCmd;
			glVertexAttrib4dv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib4f: {
			GlCmdVertexAttrib4f* pCC = (GlCmdVertexAttrib4f*)pCmd;
			glVertexAttrib4f(pCC->mIndex, pCC->mX, pCC->mY, pCC->mZ, pCC->mW);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib4fv: {
			GlCmdVertexAttrib4fv* pCC = (GlCmdVertexAttrib4fv*)pCmd;
			glVertexAttrib4fv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib4iv: {
			GlCmdVertexAttrib4iv* pCC = (GlCmdVertexAttrib4iv*)pCmd;
			glVertexAttrib4iv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib4s: {
			GlCmdVertexAttrib4s* pCC = (GlCmdVertexAttrib4s*)pCmd;
			glVertexAttrib4s(pCC->mIndex, pCC->mX, pCC->mY, pCC->mZ, pCC->mW);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib4sv: {
			GlCmdVertexAttrib4sv* pCC = (GlCmdVertexAttrib4sv*)pCmd;
			glVertexAttrib4sv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib4ubv: {
			GlCmdVertexAttrib4ubv* pCC = (GlCmdVertexAttrib4ubv*)pCmd;
			glVertexAttrib4ubv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib4uiv: {
			GlCmdVertexAttrib4uiv* pCC = (GlCmdVertexAttrib4uiv*)pCmd;
			glVertexAttrib4uiv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttrib4usv: {
			GlCmdVertexAttrib4usv* pCC = (GlCmdVertexAttrib4usv*)pCmd;
			glVertexAttrib4usv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribPointer: {
			GlCmdVertexAttribPointer* pCC = (GlCmdVertexAttribPointer*)pCmd;
			glVertexAttribPointer(pCC->mIndex, pCC->mSize, pCC->mType, pCC->mNormalized, pCC->mStride, pCC->mPointer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_UniformMatrix2x3fv: {
			GlCmdUniformMatrix2x3fv* pCC = (GlCmdUniformMatrix2x3fv*)pCmd;
			glUniformMatrix2x3fv(pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_UniformMatrix3x2fv: {
			GlCmdUniformMatrix3x2fv* pCC = (GlCmdUniformMatrix3x2fv*)pCmd;
			glUniformMatrix3x2fv(pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_UniformMatrix2x4fv: {
			GlCmdUniformMatrix2x4fv* pCC = (GlCmdUniformMatrix2x4fv*)pCmd;
			glUniformMatrix2x4fv(pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_UniformMatrix4x2fv: {
			GlCmdUniformMatrix4x2fv* pCC = (GlCmdUniformMatrix4x2fv*)pCmd;
			glUniformMatrix4x2fv(pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_UniformMatrix3x4fv: {
			GlCmdUniformMatrix3x4fv* pCC = (GlCmdUniformMatrix3x4fv*)pCmd;
			glUniformMatrix3x4fv(pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_UniformMatrix4x3fv: {
			GlCmdUniformMatrix4x3fv* pCC = (GlCmdUniformMatrix4x3fv*)pCmd;
			glUniformMatrix4x3fv(pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ColorMaski: {
			GlCmdColorMaski* pCC = (GlCmdColorMaski*)pCmd;
			glColorMaski(pCC->mIndex, pCC->mR, pCC->mG, pCC->mB, pCC->mA);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetBooleani_v: {
			GlCmdGetBooleani_v* pCC = (GlCmdGetBooleani_v*)pCmd;
			glGetBooleani_v(pCC->mTarget, pCC->mIndex, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetIntegeri_v: {
			GlCmdGetIntegeri_v* pCC = (GlCmdGetIntegeri_v*)pCmd;
			glGetIntegeri_v(pCC->mTarget, pCC->mIndex, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Enablei: {
			GlCmdEnablei* pCC = (GlCmdEnablei*)pCmd;
			glEnablei(pCC->mTarget, pCC->mIndex);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Disablei: {
			GlCmdDisablei* pCC = (GlCmdDisablei*)pCmd;
			glDisablei(pCC->mTarget, pCC->mIndex);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_IsEnabledi: {
			GlCmdIsEnabledi* pCC = (GlCmdIsEnabledi*)pCmd;
			glIsEnabledi(pCC->mTarget, pCC->mIndex);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BeginTransformFeedback: {
			GlCmdBeginTransformFeedback* pCC = (GlCmdBeginTransformFeedback*)pCmd;
			glBeginTransformFeedback(pCC->mPrimitivemode);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_EndTransformFeedback: {
			GlCmdEndTransformFeedback* pCC = (GlCmdEndTransformFeedback*)pCmd;
			glEndTransformFeedback();
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BindBufferRange: {
			GlCmdBindBufferRange* pCC = (GlCmdBindBufferRange*)pCmd;
			glBindBufferRange(pCC->mTarget, pCC->mIndex, pCC->mBuffer, pCC->mOffset, pCC->mSize);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BindBufferBase: {
			GlCmdBindBufferBase* pCC = (GlCmdBindBufferBase*)pCmd;
			glBindBufferBase(pCC->mTarget, pCC->mIndex, pCC->mBuffer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TransformFeedbackVaryings: {
			GlCmdTransformFeedbackVaryings* pCC = (GlCmdTransformFeedbackVaryings*)pCmd;
			glTransformFeedbackVaryings(pCC->mProgram, pCC->mCount, pCC->mVaryings, pCC->mBuffermode);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetTransformFeedbackVarying: {
			GlCmdGetTransformFeedbackVarying* pCC = (GlCmdGetTransformFeedbackVarying*)pCmd;
			glGetTransformFeedbackVarying(pCC->mProgram, pCC->mIndex, pCC->mBufsize, pCC->mLength, pCC->mSize, pCC->mType, pCC->mName);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ClampColor: {
			GlCmdClampColor* pCC = (GlCmdClampColor*)pCmd;
			glClampColor(pCC->mTarget, pCC->mClamp);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BeginConditionalRender: {
			GlCmdBeginConditionalRender* pCC = (GlCmdBeginConditionalRender*)pCmd;
			glBeginConditionalRender(pCC->mId, pCC->mMode);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_EndConditionalRender: {
			GlCmdEndConditionalRender* pCC = (GlCmdEndConditionalRender*)pCmd;
			glEndConditionalRender();
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribIPointer: {
			GlCmdVertexAttribIPointer* pCC = (GlCmdVertexAttribIPointer*)pCmd;
			glVertexAttribIPointer(pCC->mIndex, pCC->mSize, pCC->mType, pCC->mStride, pCC->mPointer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetVertexAttribIiv: {
			GlCmdGetVertexAttribIiv* pCC = (GlCmdGetVertexAttribIiv*)pCmd;
			glGetVertexAttribIiv(pCC->mIndex, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetVertexAttribIuiv: {
			GlCmdGetVertexAttribIuiv* pCC = (GlCmdGetVertexAttribIuiv*)pCmd;
			glGetVertexAttribIuiv(pCC->mIndex, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribI1i: {
			GlCmdVertexAttribI1i* pCC = (GlCmdVertexAttribI1i*)pCmd;
			glVertexAttribI1i(pCC->mIndex, pCC->mX);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribI2i: {
			GlCmdVertexAttribI2i* pCC = (GlCmdVertexAttribI2i*)pCmd;
			glVertexAttribI2i(pCC->mIndex, pCC->mX, pCC->mY);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribI3i: {
			GlCmdVertexAttribI3i* pCC = (GlCmdVertexAttribI3i*)pCmd;
			glVertexAttribI3i(pCC->mIndex, pCC->mX, pCC->mY, pCC->mZ);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribI4i: {
			GlCmdVertexAttribI4i* pCC = (GlCmdVertexAttribI4i*)pCmd;
			glVertexAttribI4i(pCC->mIndex, pCC->mX, pCC->mY, pCC->mZ, pCC->mW);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribI1ui: {
			GlCmdVertexAttribI1ui* pCC = (GlCmdVertexAttribI1ui*)pCmd;
			glVertexAttribI1ui(pCC->mIndex, pCC->mX);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribI2ui: {
			GlCmdVertexAttribI2ui* pCC = (GlCmdVertexAttribI2ui*)pCmd;
			glVertexAttribI2ui(pCC->mIndex, pCC->mX, pCC->mY);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribI3ui: {
			GlCmdVertexAttribI3ui* pCC = (GlCmdVertexAttribI3ui*)pCmd;
			glVertexAttribI3ui(pCC->mIndex, pCC->mX, pCC->mY, pCC->mZ);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribI4ui: {
			GlCmdVertexAttribI4ui* pCC = (GlCmdVertexAttribI4ui*)pCmd;
			glVertexAttribI4ui(pCC->mIndex, pCC->mX, pCC->mY, pCC->mZ, pCC->mW);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribI1iv: {
			GlCmdVertexAttribI1iv* pCC = (GlCmdVertexAttribI1iv*)pCmd;
			glVertexAttribI1iv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribI2iv: {
			GlCmdVertexAttribI2iv* pCC = (GlCmdVertexAttribI2iv*)pCmd;
			glVertexAttribI2iv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribI3iv: {
			GlCmdVertexAttribI3iv* pCC = (GlCmdVertexAttribI3iv*)pCmd;
			glVertexAttribI3iv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribI4iv: {
			GlCmdVertexAttribI4iv* pCC = (GlCmdVertexAttribI4iv*)pCmd;
			glVertexAttribI4iv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribI1uiv: {
			GlCmdVertexAttribI1uiv* pCC = (GlCmdVertexAttribI1uiv*)pCmd;
			glVertexAttribI1uiv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribI2uiv: {
			GlCmdVertexAttribI2uiv* pCC = (GlCmdVertexAttribI2uiv*)pCmd;
			glVertexAttribI2uiv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribI3uiv: {
			GlCmdVertexAttribI3uiv* pCC = (GlCmdVertexAttribI3uiv*)pCmd;
			glVertexAttribI3uiv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribI4uiv: {
			GlCmdVertexAttribI4uiv* pCC = (GlCmdVertexAttribI4uiv*)pCmd;
			glVertexAttribI4uiv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribI4bv: {
			GlCmdVertexAttribI4bv* pCC = (GlCmdVertexAttribI4bv*)pCmd;
			glVertexAttribI4bv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribI4sv: {
			GlCmdVertexAttribI4sv* pCC = (GlCmdVertexAttribI4sv*)pCmd;
			glVertexAttribI4sv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribI4ubv: {
			GlCmdVertexAttribI4ubv* pCC = (GlCmdVertexAttribI4ubv*)pCmd;
			glVertexAttribI4ubv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribI4usv: {
			GlCmdVertexAttribI4usv* pCC = (GlCmdVertexAttribI4usv*)pCmd;
			glVertexAttribI4usv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetUniformuiv: {
			GlCmdGetUniformuiv* pCC = (GlCmdGetUniformuiv*)pCmd;
			glGetUniformuiv(pCC->mProgram, pCC->mLocation, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BindFragDataLocation: {
			GlCmdBindFragDataLocation* pCC = (GlCmdBindFragDataLocation*)pCmd;
			glBindFragDataLocation(pCC->mProgram, pCC->mColor, pCC->mName);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetFragDataLocation: {
			GlCmdGetFragDataLocation* pCC = (GlCmdGetFragDataLocation*)pCmd;
			glGetFragDataLocation(pCC->mProgram, pCC->mName);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform1ui: {
			GlCmdUniform1ui* pCC = (GlCmdUniform1ui*)pCmd;
			glUniform1ui(pCC->mLocation, pCC->mV0);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform2ui: {
			GlCmdUniform2ui* pCC = (GlCmdUniform2ui*)pCmd;
			glUniform2ui(pCC->mLocation, pCC->mV0, pCC->mV1);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform3ui: {
			GlCmdUniform3ui* pCC = (GlCmdUniform3ui*)pCmd;
			glUniform3ui(pCC->mLocation, pCC->mV0, pCC->mV1, pCC->mV2);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform4ui: {
			GlCmdUniform4ui* pCC = (GlCmdUniform4ui*)pCmd;
			glUniform4ui(pCC->mLocation, pCC->mV0, pCC->mV1, pCC->mV2, pCC->mV3);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform1uiv: {
			GlCmdUniform1uiv* pCC = (GlCmdUniform1uiv*)pCmd;
			glUniform1uiv(pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform2uiv: {
			GlCmdUniform2uiv* pCC = (GlCmdUniform2uiv*)pCmd;
			glUniform2uiv(pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform3uiv: {
			GlCmdUniform3uiv* pCC = (GlCmdUniform3uiv*)pCmd;
			glUniform3uiv(pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform4uiv: {
			GlCmdUniform4uiv* pCC = (GlCmdUniform4uiv*)pCmd;
			glUniform4uiv(pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TexParameterIiv: {
			GlCmdTexParameterIiv* pCC = (GlCmdTexParameterIiv*)pCmd;
			glTexParameterIiv(pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TexParameterIuiv: {
			GlCmdTexParameterIuiv* pCC = (GlCmdTexParameterIuiv*)pCmd;
			glTexParameterIuiv(pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetTexParameterIiv: {
			GlCmdGetTexParameterIiv* pCC = (GlCmdGetTexParameterIiv*)pCmd;
			glGetTexParameterIiv(pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetTexParameterIuiv: {
			GlCmdGetTexParameterIuiv* pCC = (GlCmdGetTexParameterIuiv*)pCmd;
			glGetTexParameterIuiv(pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ClearBufferiv: {
			GlCmdClearBufferiv* pCC = (GlCmdClearBufferiv*)pCmd;
			glClearBufferiv(pCC->mBuffer, pCC->mDrawbuffer, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ClearBufferuiv: {
			GlCmdClearBufferuiv* pCC = (GlCmdClearBufferuiv*)pCmd;
			glClearBufferuiv(pCC->mBuffer, pCC->mDrawbuffer, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ClearBufferfv: {
			GlCmdClearBufferfv* pCC = (GlCmdClearBufferfv*)pCmd;
			glClearBufferfv(pCC->mBuffer, pCC->mDrawbuffer, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ClearBufferfi: {
			GlCmdClearBufferfi* pCC = (GlCmdClearBufferfi*)pCmd;
			glClearBufferfi(pCC->mBuffer, pCC->mDrawbuffer, pCC->mDepth, pCC->mStencil);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetStringi: {
			GlCmdGetStringi* pCC = (GlCmdGetStringi*)pCmd;
			glGetStringi(pCC->mName, pCC->mIndex);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_IsRenderbuffer: {
			GlCmdIsRenderbuffer* pCC = (GlCmdIsRenderbuffer*)pCmd;
			glIsRenderbuffer(pCC->mRenderbuffer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BindRenderbuffer: {
			GlCmdBindRenderbuffer* pCC = (GlCmdBindRenderbuffer*)pCmd;
			glBindRenderbuffer(pCC->mTarget, pCC->mRenderbuffer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DeleteRenderbuffers: {
			GlCmdDeleteRenderbuffers* pCC = (GlCmdDeleteRenderbuffers*)pCmd;
			glDeleteRenderbuffers(pCC->mN, pCC->mRenderbuffers);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GenRenderbuffers: {
			GlCmdGenRenderbuffers* pCC = (GlCmdGenRenderbuffers*)pCmd;
			glGenRenderbuffers(pCC->mN, pCC->mRenderbuffers);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_RenderbufferStorage: {
			GlCmdRenderbufferStorage* pCC = (GlCmdRenderbufferStorage*)pCmd;
			glRenderbufferStorage(pCC->mTarget, pCC->mInternalformat, pCC->mWidth, pCC->mHeight);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetRenderbufferParameteriv: {
			GlCmdGetRenderbufferParameteriv* pCC = (GlCmdGetRenderbufferParameteriv*)pCmd;
			glGetRenderbufferParameteriv(pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_IsFramebuffer: {
			GlCmdIsFramebuffer* pCC = (GlCmdIsFramebuffer*)pCmd;
			glIsFramebuffer(pCC->mFramebuffer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BindFramebuffer: {
			GlCmdBindFramebuffer* pCC = (GlCmdBindFramebuffer*)pCmd;
			glBindFramebuffer(pCC->mTarget, pCC->mFramebuffer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DeleteFramebuffers: {
			GlCmdDeleteFramebuffers* pCC = (GlCmdDeleteFramebuffers*)pCmd;
			glDeleteFramebuffers(pCC->mN, pCC->mFramebuffers);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GenFramebuffers: {
			GlCmdGenFramebuffers* pCC = (GlCmdGenFramebuffers*)pCmd;
			glGenFramebuffers(pCC->mN, pCC->mFramebuffers);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CheckFramebufferStatus: {
			GlCmdCheckFramebufferStatus* pCC = (GlCmdCheckFramebufferStatus*)pCmd;
			glCheckFramebufferStatus(pCC->mTarget);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_FramebufferTexture1D: {
			GlCmdFramebufferTexture1D* pCC = (GlCmdFramebufferTexture1D*)pCmd;
			glFramebufferTexture1D(pCC->mTarget, pCC->mAttachment, pCC->mTextarget, pCC->mTexture, pCC->mLevel);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_FramebufferTexture2D: {
			GlCmdFramebufferTexture2D* pCC = (GlCmdFramebufferTexture2D*)pCmd;
			glFramebufferTexture2D(pCC->mTarget, pCC->mAttachment, pCC->mTextarget, pCC->mTexture, pCC->mLevel);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_FramebufferTexture3D: {
			GlCmdFramebufferTexture3D* pCC = (GlCmdFramebufferTexture3D*)pCmd;
			glFramebufferTexture3D(pCC->mTarget, pCC->mAttachment, pCC->mTextarget, pCC->mTexture, pCC->mLevel, pCC->mZoffset);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_FramebufferRenderbuffer: {
			GlCmdFramebufferRenderbuffer* pCC = (GlCmdFramebufferRenderbuffer*)pCmd;
			glFramebufferRenderbuffer(pCC->mTarget, pCC->mAttachment, pCC->mRenderbuffertarget, pCC->mRenderbuffer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetFramebufferAttachmentParameteriv: {
			GlCmdGetFramebufferAttachmentParameteriv* pCC = (GlCmdGetFramebufferAttachmentParameteriv*)pCmd;
			glGetFramebufferAttachmentParameteriv(pCC->mTarget, pCC->mAttachment, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GenerateMipmap: {
			GlCmdGenerateMipmap* pCC = (GlCmdGenerateMipmap*)pCmd;
			glGenerateMipmap(pCC->mTarget);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BlitFramebuffer: {
			GlCmdBlitFramebuffer* pCC = (GlCmdBlitFramebuffer*)pCmd;
			glBlitFramebuffer(pCC->mSrcx0, pCC->mSrcy0, pCC->mSrcx1, pCC->mSrcy1, pCC->mDstx0, pCC->mDsty0, pCC->mDstx1, pCC->mDsty1, pCC->mMask, pCC->mFilter);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_RenderbufferStorageMultisample: {
			GlCmdRenderbufferStorageMultisample* pCC = (GlCmdRenderbufferStorageMultisample*)pCmd;
			glRenderbufferStorageMultisample(pCC->mTarget, pCC->mSamples, pCC->mInternalformat, pCC->mWidth, pCC->mHeight);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_FramebufferTextureLayer: {
			GlCmdFramebufferTextureLayer* pCC = (GlCmdFramebufferTextureLayer*)pCmd;
			glFramebufferTextureLayer(pCC->mTarget, pCC->mAttachment, pCC->mTexture, pCC->mLevel, pCC->mLayer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MapBufferRange: {
			GlCmdMapBufferRange* pCC = (GlCmdMapBufferRange*)pCmd;
			glMapBufferRange(pCC->mTarget, pCC->mOffset, pCC->mLength, pCC->mAccess);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_FlushMappedBufferRange: {
			GlCmdFlushMappedBufferRange* pCC = (GlCmdFlushMappedBufferRange*)pCmd;
			glFlushMappedBufferRange(pCC->mTarget, pCC->mOffset, pCC->mLength);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BindVertexArray: {
			GlCmdBindVertexArray* pCC = (GlCmdBindVertexArray*)pCmd;
			glBindVertexArray(pCC->mArray);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DeleteVertexArrays: {
			GlCmdDeleteVertexArrays* pCC = (GlCmdDeleteVertexArrays*)pCmd;
			glDeleteVertexArrays(pCC->mN, pCC->mArrays);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GenVertexArrays: {
			GlCmdGenVertexArrays* pCC = (GlCmdGenVertexArrays*)pCmd;
			glGenVertexArrays(pCC->mN, pCC->mArrays);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_IsVertexArray: {
			GlCmdIsVertexArray* pCC = (GlCmdIsVertexArray*)pCmd;
			glIsVertexArray(pCC->mArray);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DrawArraysInstanced: {
			GlCmdDrawArraysInstanced* pCC = (GlCmdDrawArraysInstanced*)pCmd;
			glDrawArraysInstanced(pCC->mMode, pCC->mFirst, pCC->mCount, pCC->mInstancecount);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DrawElementsInstanced: {
			GlCmdDrawElementsInstanced* pCC = (GlCmdDrawElementsInstanced*)pCmd;
			glDrawElementsInstanced(pCC->mMode, pCC->mCount, pCC->mType, pCC->mIndices, pCC->mInstancecount);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TexBuffer: {
			GlCmdTexBuffer* pCC = (GlCmdTexBuffer*)pCmd;
			glTexBuffer(pCC->mTarget, pCC->mInternalformat, pCC->mBuffer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_PrimitiveRestartIndex: {
			GlCmdPrimitiveRestartIndex* pCC = (GlCmdPrimitiveRestartIndex*)pCmd;
			glPrimitiveRestartIndex(pCC->mIndex);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CopyBufferSubData: {
			GlCmdCopyBufferSubData* pCC = (GlCmdCopyBufferSubData*)pCmd;
			glCopyBufferSubData(pCC->mReadtarget, pCC->mWritetarget, pCC->mReadoffset, pCC->mWriteoffset, pCC->mSize);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetUniformIndices: {
			GlCmdGetUniformIndices* pCC = (GlCmdGetUniformIndices*)pCmd;
			glGetUniformIndices(pCC->mProgram, pCC->mUniformcount, pCC->mUniformnames, pCC->mUniformindices);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetActiveUniformsiv: {
			GlCmdGetActiveUniformsiv* pCC = (GlCmdGetActiveUniformsiv*)pCmd;
			glGetActiveUniformsiv(pCC->mProgram, pCC->mUniformcount, pCC->mUniformindices, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetActiveUniformName: {
			GlCmdGetActiveUniformName* pCC = (GlCmdGetActiveUniformName*)pCmd;
			glGetActiveUniformName(pCC->mProgram, pCC->mUniformindex, pCC->mBufsize, pCC->mLength, pCC->mUniformname);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetUniformBlockIndex: {
			GlCmdGetUniformBlockIndex* pCC = (GlCmdGetUniformBlockIndex*)pCmd;
			glGetUniformBlockIndex(pCC->mProgram, pCC->mUniformblockname);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetActiveUniformBlockiv: {
			GlCmdGetActiveUniformBlockiv* pCC = (GlCmdGetActiveUniformBlockiv*)pCmd;
			glGetActiveUniformBlockiv(pCC->mProgram, pCC->mUniformblockindex, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetActiveUniformBlockName: {
			GlCmdGetActiveUniformBlockName* pCC = (GlCmdGetActiveUniformBlockName*)pCmd;
			glGetActiveUniformBlockName(pCC->mProgram, pCC->mUniformblockindex, pCC->mBufsize, pCC->mLength, pCC->mUniformblockname);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_UniformBlockBinding: {
			GlCmdUniformBlockBinding* pCC = (GlCmdUniformBlockBinding*)pCmd;
			glUniformBlockBinding(pCC->mProgram, pCC->mUniformblockindex, pCC->mUniformblockbinding);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DrawElementsBaseVertex: {
			GlCmdDrawElementsBaseVertex* pCC = (GlCmdDrawElementsBaseVertex*)pCmd;
			glDrawElementsBaseVertex(pCC->mMode, pCC->mCount, pCC->mType, pCC->mIndices, pCC->mBasevertex);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DrawRangeElementsBaseVertex: {
			GlCmdDrawRangeElementsBaseVertex* pCC = (GlCmdDrawRangeElementsBaseVertex*)pCmd;
			glDrawRangeElementsBaseVertex(pCC->mMode, pCC->mStart, pCC->mEnd, pCC->mCount, pCC->mType, pCC->mIndices, pCC->mBasevertex);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DrawElementsInstancedBaseVertex: {
			GlCmdDrawElementsInstancedBaseVertex* pCC = (GlCmdDrawElementsInstancedBaseVertex*)pCmd;
			glDrawElementsInstancedBaseVertex(pCC->mMode, pCC->mCount, pCC->mType, pCC->mIndices, pCC->mInstancecount, pCC->mBasevertex);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiDrawElementsBaseVertex: {
			GlCmdMultiDrawElementsBaseVertex* pCC = (GlCmdMultiDrawElementsBaseVertex*)pCmd;
			glMultiDrawElementsBaseVertex(pCC->mMode, pCC->mCount, pCC->mType, pCC->mIndices, pCC->mDrawcount, pCC->mBasevertex);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProvokingVertex: {
			GlCmdProvokingVertex* pCC = (GlCmdProvokingVertex*)pCmd;
			glProvokingVertex(pCC->mMode);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_FenceSync: {
			GlCmdFenceSync* pCC = (GlCmdFenceSync*)pCmd;
			glFenceSync(pCC->mCondition, pCC->mFlags);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_IsSync: {
			GlCmdIsSync* pCC = (GlCmdIsSync*)pCmd;
			glIsSync(pCC->mSync);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DeleteSync: {
			GlCmdDeleteSync* pCC = (GlCmdDeleteSync*)pCmd;
			glDeleteSync(pCC->mSync);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ClientWaitSync: {
			GlCmdClientWaitSync* pCC = (GlCmdClientWaitSync*)pCmd;
			glClientWaitSync(pCC->mSync, pCC->mFlags, pCC->mTimeout);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_WaitSync: {
			GlCmdWaitSync* pCC = (GlCmdWaitSync*)pCmd;
			glWaitSync(pCC->mSync, pCC->mFlags, pCC->mTimeout);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetInteger64v: {
			GlCmdGetInteger64v* pCC = (GlCmdGetInteger64v*)pCmd;
			glGetInteger64v(pCC->mPname, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetSynciv: {
			GlCmdGetSynciv* pCC = (GlCmdGetSynciv*)pCmd;
			glGetSynciv(pCC->mSync, pCC->mPname, pCC->mBufsize, pCC->mLength, pCC->mValues);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetInteger64i_v: {
			GlCmdGetInteger64i_v* pCC = (GlCmdGetInteger64i_v*)pCmd;
			glGetInteger64i_v(pCC->mTarget, pCC->mIndex, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetBufferParameteri64v: {
			GlCmdGetBufferParameteri64v* pCC = (GlCmdGetBufferParameteri64v*)pCmd;
			glGetBufferParameteri64v(pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_FramebufferTexture: {
			GlCmdFramebufferTexture* pCC = (GlCmdFramebufferTexture*)pCmd;
			glFramebufferTexture(pCC->mTarget, pCC->mAttachment, pCC->mTexture, pCC->mLevel);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TexImage2DMultisample: {
			GlCmdTexImage2DMultisample* pCC = (GlCmdTexImage2DMultisample*)pCmd;
			glTexImage2DMultisample(pCC->mTarget, pCC->mSamples, pCC->mInternalformat, pCC->mWidth, pCC->mHeight, pCC->mFixedsamplelocations);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TexImage3DMultisample: {
			GlCmdTexImage3DMultisample* pCC = (GlCmdTexImage3DMultisample*)pCmd;
			glTexImage3DMultisample(pCC->mTarget, pCC->mSamples, pCC->mInternalformat, pCC->mWidth, pCC->mHeight, pCC->mDepth, pCC->mFixedsamplelocations);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetMultisamplefv: {
			GlCmdGetMultisamplefv* pCC = (GlCmdGetMultisamplefv*)pCmd;
			glGetMultisamplefv(pCC->mPname, pCC->mIndex, pCC->mVal);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_SampleMaski: {
			GlCmdSampleMaski* pCC = (GlCmdSampleMaski*)pCmd;
			glSampleMaski(pCC->mMasknumber, pCC->mMask);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BindFragDataLocationIndexed: {
			GlCmdBindFragDataLocationIndexed* pCC = (GlCmdBindFragDataLocationIndexed*)pCmd;
			glBindFragDataLocationIndexed(pCC->mProgram, pCC->mColornumber, pCC->mIndex, pCC->mName);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetFragDataIndex: {
			GlCmdGetFragDataIndex* pCC = (GlCmdGetFragDataIndex*)pCmd;
			glGetFragDataIndex(pCC->mProgram, pCC->mName);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GenSamplers: {
			GlCmdGenSamplers* pCC = (GlCmdGenSamplers*)pCmd;
			glGenSamplers(pCC->mCount, pCC->mSamplers);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DeleteSamplers: {
			GlCmdDeleteSamplers* pCC = (GlCmdDeleteSamplers*)pCmd;
			glDeleteSamplers(pCC->mCount, pCC->mSamplers);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_IsSampler: {
			GlCmdIsSampler* pCC = (GlCmdIsSampler*)pCmd;
			glIsSampler(pCC->mSampler);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BindSampler: {
			GlCmdBindSampler* pCC = (GlCmdBindSampler*)pCmd;
			glBindSampler(pCC->mUnit, pCC->mSampler);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_SamplerParameteri: {
			GlCmdSamplerParameteri* pCC = (GlCmdSamplerParameteri*)pCmd;
			glSamplerParameteri(pCC->mSampler, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_SamplerParameteriv: {
			GlCmdSamplerParameteriv* pCC = (GlCmdSamplerParameteriv*)pCmd;
			glSamplerParameteriv(pCC->mSampler, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_SamplerParameterf: {
			GlCmdSamplerParameterf* pCC = (GlCmdSamplerParameterf*)pCmd;
			glSamplerParameterf(pCC->mSampler, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_SamplerParameterfv: {
			GlCmdSamplerParameterfv* pCC = (GlCmdSamplerParameterfv*)pCmd;
			glSamplerParameterfv(pCC->mSampler, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_SamplerParameterIiv: {
			GlCmdSamplerParameterIiv* pCC = (GlCmdSamplerParameterIiv*)pCmd;
			glSamplerParameterIiv(pCC->mSampler, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_SamplerParameterIuiv: {
			GlCmdSamplerParameterIuiv* pCC = (GlCmdSamplerParameterIuiv*)pCmd;
			glSamplerParameterIuiv(pCC->mSampler, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetSamplerParameteriv: {
			GlCmdGetSamplerParameteriv* pCC = (GlCmdGetSamplerParameteriv*)pCmd;
			glGetSamplerParameteriv(pCC->mSampler, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetSamplerParameterIiv: {
			GlCmdGetSamplerParameterIiv* pCC = (GlCmdGetSamplerParameterIiv*)pCmd;
			glGetSamplerParameterIiv(pCC->mSampler, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetSamplerParameterfv: {
			GlCmdGetSamplerParameterfv* pCC = (GlCmdGetSamplerParameterfv*)pCmd;
			glGetSamplerParameterfv(pCC->mSampler, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetSamplerParameterIuiv: {
			GlCmdGetSamplerParameterIuiv* pCC = (GlCmdGetSamplerParameterIuiv*)pCmd;
			glGetSamplerParameterIuiv(pCC->mSampler, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_QueryCounter: {
			GlCmdQueryCounter* pCC = (GlCmdQueryCounter*)pCmd;
			glQueryCounter(pCC->mId, pCC->mTarget);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetQueryObjecti64v: {
			GlCmdGetQueryObjecti64v* pCC = (GlCmdGetQueryObjecti64v*)pCmd;
			glGetQueryObjecti64v(pCC->mId, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetQueryObjectui64v: {
			GlCmdGetQueryObjectui64v* pCC = (GlCmdGetQueryObjectui64v*)pCmd;
			glGetQueryObjectui64v(pCC->mId, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribDivisor: {
			GlCmdVertexAttribDivisor* pCC = (GlCmdVertexAttribDivisor*)pCmd;
			glVertexAttribDivisor(pCC->mIndex, pCC->mDivisor);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribP1ui: {
			GlCmdVertexAttribP1ui* pCC = (GlCmdVertexAttribP1ui*)pCmd;
			glVertexAttribP1ui(pCC->mIndex, pCC->mType, pCC->mNormalized, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribP1uiv: {
			GlCmdVertexAttribP1uiv* pCC = (GlCmdVertexAttribP1uiv*)pCmd;
			glVertexAttribP1uiv(pCC->mIndex, pCC->mType, pCC->mNormalized, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribP2ui: {
			GlCmdVertexAttribP2ui* pCC = (GlCmdVertexAttribP2ui*)pCmd;
			glVertexAttribP2ui(pCC->mIndex, pCC->mType, pCC->mNormalized, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribP2uiv: {
			GlCmdVertexAttribP2uiv* pCC = (GlCmdVertexAttribP2uiv*)pCmd;
			glVertexAttribP2uiv(pCC->mIndex, pCC->mType, pCC->mNormalized, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribP3ui: {
			GlCmdVertexAttribP3ui* pCC = (GlCmdVertexAttribP3ui*)pCmd;
			glVertexAttribP3ui(pCC->mIndex, pCC->mType, pCC->mNormalized, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribP3uiv: {
			GlCmdVertexAttribP3uiv* pCC = (GlCmdVertexAttribP3uiv*)pCmd;
			glVertexAttribP3uiv(pCC->mIndex, pCC->mType, pCC->mNormalized, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribP4ui: {
			GlCmdVertexAttribP4ui* pCC = (GlCmdVertexAttribP4ui*)pCmd;
			glVertexAttribP4ui(pCC->mIndex, pCC->mType, pCC->mNormalized, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribP4uiv: {
			GlCmdVertexAttribP4uiv* pCC = (GlCmdVertexAttribP4uiv*)pCmd;
			glVertexAttribP4uiv(pCC->mIndex, pCC->mType, pCC->mNormalized, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MinSampleShading: {
			GlCmdMinSampleShading* pCC = (GlCmdMinSampleShading*)pCmd;
			glMinSampleShading(pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BlendEquationi: {
			GlCmdBlendEquationi* pCC = (GlCmdBlendEquationi*)pCmd;
			glBlendEquationi(pCC->mBuf, pCC->mMode);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BlendEquationSeparatei: {
			GlCmdBlendEquationSeparatei* pCC = (GlCmdBlendEquationSeparatei*)pCmd;
			glBlendEquationSeparatei(pCC->mBuf, pCC->mModergb, pCC->mModealpha);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BlendFunci: {
			GlCmdBlendFunci* pCC = (GlCmdBlendFunci*)pCmd;
			glBlendFunci(pCC->mBuf, pCC->mSrc, pCC->mDst);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BlendFuncSeparatei: {
			GlCmdBlendFuncSeparatei* pCC = (GlCmdBlendFuncSeparatei*)pCmd;
			glBlendFuncSeparatei(pCC->mBuf, pCC->mSrcrgb, pCC->mDstrgb, pCC->mSrcalpha, pCC->mDstalpha);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DrawArraysIndirect: {
			GlCmdDrawArraysIndirect* pCC = (GlCmdDrawArraysIndirect*)pCmd;
			glDrawArraysIndirect(pCC->mMode, pCC->mIndirect);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DrawElementsIndirect: {
			GlCmdDrawElementsIndirect* pCC = (GlCmdDrawElementsIndirect*)pCmd;
			glDrawElementsIndirect(pCC->mMode, pCC->mType, pCC->mIndirect);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform1d: {
			GlCmdUniform1d* pCC = (GlCmdUniform1d*)pCmd;
			glUniform1d(pCC->mLocation, pCC->mX);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform2d: {
			GlCmdUniform2d* pCC = (GlCmdUniform2d*)pCmd;
			glUniform2d(pCC->mLocation, pCC->mX, pCC->mY);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform3d: {
			GlCmdUniform3d* pCC = (GlCmdUniform3d*)pCmd;
			glUniform3d(pCC->mLocation, pCC->mX, pCC->mY, pCC->mZ);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform4d: {
			GlCmdUniform4d* pCC = (GlCmdUniform4d*)pCmd;
			glUniform4d(pCC->mLocation, pCC->mX, pCC->mY, pCC->mZ, pCC->mW);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform1dv: {
			GlCmdUniform1dv* pCC = (GlCmdUniform1dv*)pCmd;
			glUniform1dv(pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform2dv: {
			GlCmdUniform2dv* pCC = (GlCmdUniform2dv*)pCmd;
			glUniform2dv(pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform3dv: {
			GlCmdUniform3dv* pCC = (GlCmdUniform3dv*)pCmd;
			glUniform3dv(pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform4dv: {
			GlCmdUniform4dv* pCC = (GlCmdUniform4dv*)pCmd;
			glUniform4dv(pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_UniformMatrix2dv: {
			GlCmdUniformMatrix2dv* pCC = (GlCmdUniformMatrix2dv*)pCmd;
			glUniformMatrix2dv(pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_UniformMatrix3dv: {
			GlCmdUniformMatrix3dv* pCC = (GlCmdUniformMatrix3dv*)pCmd;
			glUniformMatrix3dv(pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_UniformMatrix4dv: {
			GlCmdUniformMatrix4dv* pCC = (GlCmdUniformMatrix4dv*)pCmd;
			glUniformMatrix4dv(pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_UniformMatrix2x3dv: {
			GlCmdUniformMatrix2x3dv* pCC = (GlCmdUniformMatrix2x3dv*)pCmd;
			glUniformMatrix2x3dv(pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_UniformMatrix2x4dv: {
			GlCmdUniformMatrix2x4dv* pCC = (GlCmdUniformMatrix2x4dv*)pCmd;
			glUniformMatrix2x4dv(pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_UniformMatrix3x2dv: {
			GlCmdUniformMatrix3x2dv* pCC = (GlCmdUniformMatrix3x2dv*)pCmd;
			glUniformMatrix3x2dv(pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_UniformMatrix3x4dv: {
			GlCmdUniformMatrix3x4dv* pCC = (GlCmdUniformMatrix3x4dv*)pCmd;
			glUniformMatrix3x4dv(pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_UniformMatrix4x2dv: {
			GlCmdUniformMatrix4x2dv* pCC = (GlCmdUniformMatrix4x2dv*)pCmd;
			glUniformMatrix4x2dv(pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_UniformMatrix4x3dv: {
			GlCmdUniformMatrix4x3dv* pCC = (GlCmdUniformMatrix4x3dv*)pCmd;
			glUniformMatrix4x3dv(pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetUniformdv: {
			GlCmdGetUniformdv* pCC = (GlCmdGetUniformdv*)pCmd;
			glGetUniformdv(pCC->mProgram, pCC->mLocation, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetSubroutineUniformLocation: {
			GlCmdGetSubroutineUniformLocation* pCC = (GlCmdGetSubroutineUniformLocation*)pCmd;
			glGetSubroutineUniformLocation(pCC->mProgram, pCC->mShadertype, pCC->mName);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetSubroutineIndex: {
			GlCmdGetSubroutineIndex* pCC = (GlCmdGetSubroutineIndex*)pCmd;
			glGetSubroutineIndex(pCC->mProgram, pCC->mShadertype, pCC->mName);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetActiveSubroutineUniformiv: {
			GlCmdGetActiveSubroutineUniformiv* pCC = (GlCmdGetActiveSubroutineUniformiv*)pCmd;
			glGetActiveSubroutineUniformiv(pCC->mProgram, pCC->mShadertype, pCC->mIndex, pCC->mPname, pCC->mValues);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetActiveSubroutineUniformName: {
			GlCmdGetActiveSubroutineUniformName* pCC = (GlCmdGetActiveSubroutineUniformName*)pCmd;
			glGetActiveSubroutineUniformName(pCC->mProgram, pCC->mShadertype, pCC->mIndex, pCC->mBufsize, pCC->mLength, pCC->mName);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetActiveSubroutineName: {
			GlCmdGetActiveSubroutineName* pCC = (GlCmdGetActiveSubroutineName*)pCmd;
			glGetActiveSubroutineName(pCC->mProgram, pCC->mShadertype, pCC->mIndex, pCC->mBufsize, pCC->mLength, pCC->mName);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_UniformSubroutinesuiv: {
			GlCmdUniformSubroutinesuiv* pCC = (GlCmdUniformSubroutinesuiv*)pCmd;
			glUniformSubroutinesuiv(pCC->mShadertype, pCC->mCount, pCC->mIndices);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetUniformSubroutineuiv: {
			GlCmdGetUniformSubroutineuiv* pCC = (GlCmdGetUniformSubroutineuiv*)pCmd;
			glGetUniformSubroutineuiv(pCC->mShadertype, pCC->mLocation, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetProgramStageiv: {
			GlCmdGetProgramStageiv* pCC = (GlCmdGetProgramStageiv*)pCmd;
			glGetProgramStageiv(pCC->mProgram, pCC->mShadertype, pCC->mPname, pCC->mValues);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_PatchParameteri: {
			GlCmdPatchParameteri* pCC = (GlCmdPatchParameteri*)pCmd;
			glPatchParameteri(pCC->mPname, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_PatchParameterfv: {
			GlCmdPatchParameterfv* pCC = (GlCmdPatchParameterfv*)pCmd;
			glPatchParameterfv(pCC->mPname, pCC->mValues);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BindTransformFeedback: {
			GlCmdBindTransformFeedback* pCC = (GlCmdBindTransformFeedback*)pCmd;
			glBindTransformFeedback(pCC->mTarget, pCC->mId);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DeleteTransformFeedbacks: {
			GlCmdDeleteTransformFeedbacks* pCC = (GlCmdDeleteTransformFeedbacks*)pCmd;
			glDeleteTransformFeedbacks(pCC->mN, pCC->mIds);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GenTransformFeedbacks: {
			GlCmdGenTransformFeedbacks* pCC = (GlCmdGenTransformFeedbacks*)pCmd;
			glGenTransformFeedbacks(pCC->mN, pCC->mIds);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_IsTransformFeedback: {
			GlCmdIsTransformFeedback* pCC = (GlCmdIsTransformFeedback*)pCmd;
			glIsTransformFeedback(pCC->mId);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_PauseTransformFeedback: {
			GlCmdPauseTransformFeedback* pCC = (GlCmdPauseTransformFeedback*)pCmd;
			glPauseTransformFeedback();
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ResumeTransformFeedback: {
			GlCmdResumeTransformFeedback* pCC = (GlCmdResumeTransformFeedback*)pCmd;
			glResumeTransformFeedback();
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DrawTransformFeedback: {
			GlCmdDrawTransformFeedback* pCC = (GlCmdDrawTransformFeedback*)pCmd;
			glDrawTransformFeedback(pCC->mMode, pCC->mId);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DrawTransformFeedbackStream: {
			GlCmdDrawTransformFeedbackStream* pCC = (GlCmdDrawTransformFeedbackStream*)pCmd;
			glDrawTransformFeedbackStream(pCC->mMode, pCC->mId, pCC->mStream);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BeginQueryIndexed: {
			GlCmdBeginQueryIndexed* pCC = (GlCmdBeginQueryIndexed*)pCmd;
			glBeginQueryIndexed(pCC->mTarget, pCC->mIndex, pCC->mId);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_EndQueryIndexed: {
			GlCmdEndQueryIndexed* pCC = (GlCmdEndQueryIndexed*)pCmd;
			glEndQueryIndexed(pCC->mTarget, pCC->mIndex);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetQueryIndexediv: {
			GlCmdGetQueryIndexediv* pCC = (GlCmdGetQueryIndexediv*)pCmd;
			glGetQueryIndexediv(pCC->mTarget, pCC->mIndex, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ReleaseShaderCompiler: {
			GlCmdReleaseShaderCompiler* pCC = (GlCmdReleaseShaderCompiler*)pCmd;
			glReleaseShaderCompiler();
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ShaderBinary: {
			GlCmdShaderBinary* pCC = (GlCmdShaderBinary*)pCmd;
			glShaderBinary(pCC->mCount, pCC->mShaders, pCC->mBinaryformat, pCC->mBinary, pCC->mLength);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetShaderPrecisionFormat: {
			GlCmdGetShaderPrecisionFormat* pCC = (GlCmdGetShaderPrecisionFormat*)pCmd;
			glGetShaderPrecisionFormat(pCC->mShadertype, pCC->mPrecisiontype, pCC->mRange, pCC->mPrecision);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DepthRangef: {
			GlCmdDepthRangef* pCC = (GlCmdDepthRangef*)pCmd;
			glDepthRangef(pCC->mN, pCC->mF);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ClearDepthf: {
			GlCmdClearDepthf* pCC = (GlCmdClearDepthf*)pCmd;
			glClearDepthf(pCC->mD);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetProgramBinary: {
			GlCmdGetProgramBinary* pCC = (GlCmdGetProgramBinary*)pCmd;
			glGetProgramBinary(pCC->mProgram, pCC->mBufsize, pCC->mLength, pCC->mBinaryformat, pCC->mBinary);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramBinary: {
			GlCmdProgramBinary* pCC = (GlCmdProgramBinary*)pCmd;
			glProgramBinary(pCC->mProgram, pCC->mBinaryformat, pCC->mBinary, pCC->mLength);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramParameteri: {
			GlCmdProgramParameteri* pCC = (GlCmdProgramParameteri*)pCmd;
			glProgramParameteri(pCC->mProgram, pCC->mPname, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_UseProgramStages: {
			GlCmdUseProgramStages* pCC = (GlCmdUseProgramStages*)pCmd;
			glUseProgramStages(pCC->mPipeline, pCC->mStages, pCC->mProgram);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ActiveShaderProgram: {
			GlCmdActiveShaderProgram* pCC = (GlCmdActiveShaderProgram*)pCmd;
			glActiveShaderProgram(pCC->mPipeline, pCC->mProgram);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CreateShaderProgramv: {
			GlCmdCreateShaderProgramv* pCC = (GlCmdCreateShaderProgramv*)pCmd;
			glCreateShaderProgramv(pCC->mType, pCC->mCount, pCC->mStrings);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BindProgramPipeline: {
			GlCmdBindProgramPipeline* pCC = (GlCmdBindProgramPipeline*)pCmd;
			glBindProgramPipeline(pCC->mPipeline);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DeleteProgramPipelines: {
			GlCmdDeleteProgramPipelines* pCC = (GlCmdDeleteProgramPipelines*)pCmd;
			glDeleteProgramPipelines(pCC->mN, pCC->mPipelines);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GenProgramPipelines: {
			GlCmdGenProgramPipelines* pCC = (GlCmdGenProgramPipelines*)pCmd;
			glGenProgramPipelines(pCC->mN, pCC->mPipelines);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_IsProgramPipeline: {
			GlCmdIsProgramPipeline* pCC = (GlCmdIsProgramPipeline*)pCmd;
			glIsProgramPipeline(pCC->mPipeline);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetProgramPipelineiv: {
			GlCmdGetProgramPipelineiv* pCC = (GlCmdGetProgramPipelineiv*)pCmd;
			glGetProgramPipelineiv(pCC->mPipeline, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform1i: {
			GlCmdProgramUniform1i* pCC = (GlCmdProgramUniform1i*)pCmd;
			glProgramUniform1i(pCC->mProgram, pCC->mLocation, pCC->mV0);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform1iv: {
			GlCmdProgramUniform1iv* pCC = (GlCmdProgramUniform1iv*)pCmd;
			glProgramUniform1iv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform1f: {
			GlCmdProgramUniform1f* pCC = (GlCmdProgramUniform1f*)pCmd;
			glProgramUniform1f(pCC->mProgram, pCC->mLocation, pCC->mV0);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform1fv: {
			GlCmdProgramUniform1fv* pCC = (GlCmdProgramUniform1fv*)pCmd;
			glProgramUniform1fv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform1d: {
			GlCmdProgramUniform1d* pCC = (GlCmdProgramUniform1d*)pCmd;
			glProgramUniform1d(pCC->mProgram, pCC->mLocation, pCC->mV0);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform1dv: {
			GlCmdProgramUniform1dv* pCC = (GlCmdProgramUniform1dv*)pCmd;
			glProgramUniform1dv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform1ui: {
			GlCmdProgramUniform1ui* pCC = (GlCmdProgramUniform1ui*)pCmd;
			glProgramUniform1ui(pCC->mProgram, pCC->mLocation, pCC->mV0);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform1uiv: {
			GlCmdProgramUniform1uiv* pCC = (GlCmdProgramUniform1uiv*)pCmd;
			glProgramUniform1uiv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform2i: {
			GlCmdProgramUniform2i* pCC = (GlCmdProgramUniform2i*)pCmd;
			glProgramUniform2i(pCC->mProgram, pCC->mLocation, pCC->mV0, pCC->mV1);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform2iv: {
			GlCmdProgramUniform2iv* pCC = (GlCmdProgramUniform2iv*)pCmd;
			glProgramUniform2iv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform2f: {
			GlCmdProgramUniform2f* pCC = (GlCmdProgramUniform2f*)pCmd;
			glProgramUniform2f(pCC->mProgram, pCC->mLocation, pCC->mV0, pCC->mV1);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform2fv: {
			GlCmdProgramUniform2fv* pCC = (GlCmdProgramUniform2fv*)pCmd;
			glProgramUniform2fv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform2d: {
			GlCmdProgramUniform2d* pCC = (GlCmdProgramUniform2d*)pCmd;
			glProgramUniform2d(pCC->mProgram, pCC->mLocation, pCC->mV0, pCC->mV1);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform2dv: {
			GlCmdProgramUniform2dv* pCC = (GlCmdProgramUniform2dv*)pCmd;
			glProgramUniform2dv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform2ui: {
			GlCmdProgramUniform2ui* pCC = (GlCmdProgramUniform2ui*)pCmd;
			glProgramUniform2ui(pCC->mProgram, pCC->mLocation, pCC->mV0, pCC->mV1);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform2uiv: {
			GlCmdProgramUniform2uiv* pCC = (GlCmdProgramUniform2uiv*)pCmd;
			glProgramUniform2uiv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform3i: {
			GlCmdProgramUniform3i* pCC = (GlCmdProgramUniform3i*)pCmd;
			glProgramUniform3i(pCC->mProgram, pCC->mLocation, pCC->mV0, pCC->mV1, pCC->mV2);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform3iv: {
			GlCmdProgramUniform3iv* pCC = (GlCmdProgramUniform3iv*)pCmd;
			glProgramUniform3iv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform3f: {
			GlCmdProgramUniform3f* pCC = (GlCmdProgramUniform3f*)pCmd;
			glProgramUniform3f(pCC->mProgram, pCC->mLocation, pCC->mV0, pCC->mV1, pCC->mV2);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform3fv: {
			GlCmdProgramUniform3fv* pCC = (GlCmdProgramUniform3fv*)pCmd;
			glProgramUniform3fv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform3d: {
			GlCmdProgramUniform3d* pCC = (GlCmdProgramUniform3d*)pCmd;
			glProgramUniform3d(pCC->mProgram, pCC->mLocation, pCC->mV0, pCC->mV1, pCC->mV2);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform3dv: {
			GlCmdProgramUniform3dv* pCC = (GlCmdProgramUniform3dv*)pCmd;
			glProgramUniform3dv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform3ui: {
			GlCmdProgramUniform3ui* pCC = (GlCmdProgramUniform3ui*)pCmd;
			glProgramUniform3ui(pCC->mProgram, pCC->mLocation, pCC->mV0, pCC->mV1, pCC->mV2);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform3uiv: {
			GlCmdProgramUniform3uiv* pCC = (GlCmdProgramUniform3uiv*)pCmd;
			glProgramUniform3uiv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform4i: {
			GlCmdProgramUniform4i* pCC = (GlCmdProgramUniform4i*)pCmd;
			glProgramUniform4i(pCC->mProgram, pCC->mLocation, pCC->mV0, pCC->mV1, pCC->mV2, pCC->mV3);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform4iv: {
			GlCmdProgramUniform4iv* pCC = (GlCmdProgramUniform4iv*)pCmd;
			glProgramUniform4iv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform4f: {
			GlCmdProgramUniform4f* pCC = (GlCmdProgramUniform4f*)pCmd;
			glProgramUniform4f(pCC->mProgram, pCC->mLocation, pCC->mV0, pCC->mV1, pCC->mV2, pCC->mV3);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform4fv: {
			GlCmdProgramUniform4fv* pCC = (GlCmdProgramUniform4fv*)pCmd;
			glProgramUniform4fv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform4d: {
			GlCmdProgramUniform4d* pCC = (GlCmdProgramUniform4d*)pCmd;
			glProgramUniform4d(pCC->mProgram, pCC->mLocation, pCC->mV0, pCC->mV1, pCC->mV2, pCC->mV3);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform4dv: {
			GlCmdProgramUniform4dv* pCC = (GlCmdProgramUniform4dv*)pCmd;
			glProgramUniform4dv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform4ui: {
			GlCmdProgramUniform4ui* pCC = (GlCmdProgramUniform4ui*)pCmd;
			glProgramUniform4ui(pCC->mProgram, pCC->mLocation, pCC->mV0, pCC->mV1, pCC->mV2, pCC->mV3);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform4uiv: {
			GlCmdProgramUniform4uiv* pCC = (GlCmdProgramUniform4uiv*)pCmd;
			glProgramUniform4uiv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniformMatrix2fv: {
			GlCmdProgramUniformMatrix2fv* pCC = (GlCmdProgramUniformMatrix2fv*)pCmd;
			glProgramUniformMatrix2fv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniformMatrix3fv: {
			GlCmdProgramUniformMatrix3fv* pCC = (GlCmdProgramUniformMatrix3fv*)pCmd;
			glProgramUniformMatrix3fv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniformMatrix4fv: {
			GlCmdProgramUniformMatrix4fv* pCC = (GlCmdProgramUniformMatrix4fv*)pCmd;
			glProgramUniformMatrix4fv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniformMatrix2dv: {
			GlCmdProgramUniformMatrix2dv* pCC = (GlCmdProgramUniformMatrix2dv*)pCmd;
			glProgramUniformMatrix2dv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniformMatrix3dv: {
			GlCmdProgramUniformMatrix3dv* pCC = (GlCmdProgramUniformMatrix3dv*)pCmd;
			glProgramUniformMatrix3dv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniformMatrix4dv: {
			GlCmdProgramUniformMatrix4dv* pCC = (GlCmdProgramUniformMatrix4dv*)pCmd;
			glProgramUniformMatrix4dv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniformMatrix2x3fv: {
			GlCmdProgramUniformMatrix2x3fv* pCC = (GlCmdProgramUniformMatrix2x3fv*)pCmd;
			glProgramUniformMatrix2x3fv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniformMatrix3x2fv: {
			GlCmdProgramUniformMatrix3x2fv* pCC = (GlCmdProgramUniformMatrix3x2fv*)pCmd;
			glProgramUniformMatrix3x2fv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniformMatrix2x4fv: {
			GlCmdProgramUniformMatrix2x4fv* pCC = (GlCmdProgramUniformMatrix2x4fv*)pCmd;
			glProgramUniformMatrix2x4fv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniformMatrix4x2fv: {
			GlCmdProgramUniformMatrix4x2fv* pCC = (GlCmdProgramUniformMatrix4x2fv*)pCmd;
			glProgramUniformMatrix4x2fv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniformMatrix3x4fv: {
			GlCmdProgramUniformMatrix3x4fv* pCC = (GlCmdProgramUniformMatrix3x4fv*)pCmd;
			glProgramUniformMatrix3x4fv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniformMatrix4x3fv: {
			GlCmdProgramUniformMatrix4x3fv* pCC = (GlCmdProgramUniformMatrix4x3fv*)pCmd;
			glProgramUniformMatrix4x3fv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniformMatrix2x3dv: {
			GlCmdProgramUniformMatrix2x3dv* pCC = (GlCmdProgramUniformMatrix2x3dv*)pCmd;
			glProgramUniformMatrix2x3dv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniformMatrix3x2dv: {
			GlCmdProgramUniformMatrix3x2dv* pCC = (GlCmdProgramUniformMatrix3x2dv*)pCmd;
			glProgramUniformMatrix3x2dv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniformMatrix2x4dv: {
			GlCmdProgramUniformMatrix2x4dv* pCC = (GlCmdProgramUniformMatrix2x4dv*)pCmd;
			glProgramUniformMatrix2x4dv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniformMatrix4x2dv: {
			GlCmdProgramUniformMatrix4x2dv* pCC = (GlCmdProgramUniformMatrix4x2dv*)pCmd;
			glProgramUniformMatrix4x2dv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniformMatrix3x4dv: {
			GlCmdProgramUniformMatrix3x4dv* pCC = (GlCmdProgramUniformMatrix3x4dv*)pCmd;
			glProgramUniformMatrix3x4dv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniformMatrix4x3dv: {
			GlCmdProgramUniformMatrix4x3dv* pCC = (GlCmdProgramUniformMatrix4x3dv*)pCmd;
			glProgramUniformMatrix4x3dv(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ValidateProgramPipeline: {
			GlCmdValidateProgramPipeline* pCC = (GlCmdValidateProgramPipeline*)pCmd;
			glValidateProgramPipeline(pCC->mPipeline);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetProgramPipelineInfoLog: {
			GlCmdGetProgramPipelineInfoLog* pCC = (GlCmdGetProgramPipelineInfoLog*)pCmd;
			glGetProgramPipelineInfoLog(pCC->mPipeline, pCC->mBufsize, pCC->mLength, pCC->mInfolog);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribL1d: {
			GlCmdVertexAttribL1d* pCC = (GlCmdVertexAttribL1d*)pCmd;
			glVertexAttribL1d(pCC->mIndex, pCC->mX);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribL2d: {
			GlCmdVertexAttribL2d* pCC = (GlCmdVertexAttribL2d*)pCmd;
			glVertexAttribL2d(pCC->mIndex, pCC->mX, pCC->mY);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribL3d: {
			GlCmdVertexAttribL3d* pCC = (GlCmdVertexAttribL3d*)pCmd;
			glVertexAttribL3d(pCC->mIndex, pCC->mX, pCC->mY, pCC->mZ);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribL4d: {
			GlCmdVertexAttribL4d* pCC = (GlCmdVertexAttribL4d*)pCmd;
			glVertexAttribL4d(pCC->mIndex, pCC->mX, pCC->mY, pCC->mZ, pCC->mW);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribL1dv: {
			GlCmdVertexAttribL1dv* pCC = (GlCmdVertexAttribL1dv*)pCmd;
			glVertexAttribL1dv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribL2dv: {
			GlCmdVertexAttribL2dv* pCC = (GlCmdVertexAttribL2dv*)pCmd;
			glVertexAttribL2dv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribL3dv: {
			GlCmdVertexAttribL3dv* pCC = (GlCmdVertexAttribL3dv*)pCmd;
			glVertexAttribL3dv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribL4dv: {
			GlCmdVertexAttribL4dv* pCC = (GlCmdVertexAttribL4dv*)pCmd;
			glVertexAttribL4dv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribLPointer: {
			GlCmdVertexAttribLPointer* pCC = (GlCmdVertexAttribLPointer*)pCmd;
			glVertexAttribLPointer(pCC->mIndex, pCC->mSize, pCC->mType, pCC->mStride, pCC->mPointer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetVertexAttribLdv: {
			GlCmdGetVertexAttribLdv* pCC = (GlCmdGetVertexAttribLdv*)pCmd;
			glGetVertexAttribLdv(pCC->mIndex, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ViewportArrayv: {
			GlCmdViewportArrayv* pCC = (GlCmdViewportArrayv*)pCmd;
			glViewportArrayv(pCC->mFirst, pCC->mCount, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ViewportIndexedf: {
			GlCmdViewportIndexedf* pCC = (GlCmdViewportIndexedf*)pCmd;
			glViewportIndexedf(pCC->mIndex, pCC->mX, pCC->mY, pCC->mW, pCC->mH);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ViewportIndexedfv: {
			GlCmdViewportIndexedfv* pCC = (GlCmdViewportIndexedfv*)pCmd;
			glViewportIndexedfv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ScissorArrayv: {
			GlCmdScissorArrayv* pCC = (GlCmdScissorArrayv*)pCmd;
			glScissorArrayv(pCC->mFirst, pCC->mCount, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ScissorIndexed: {
			GlCmdScissorIndexed* pCC = (GlCmdScissorIndexed*)pCmd;
			glScissorIndexed(pCC->mIndex, pCC->mLeft, pCC->mBottom, pCC->mWidth, pCC->mHeight);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ScissorIndexedv: {
			GlCmdScissorIndexedv* pCC = (GlCmdScissorIndexedv*)pCmd;
			glScissorIndexedv(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DepthRangeArrayv: {
			GlCmdDepthRangeArrayv* pCC = (GlCmdDepthRangeArrayv*)pCmd;
			glDepthRangeArrayv(pCC->mFirst, pCC->mCount, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DepthRangeIndexed: {
			GlCmdDepthRangeIndexed* pCC = (GlCmdDepthRangeIndexed*)pCmd;
			glDepthRangeIndexed(pCC->mIndex, pCC->mN, pCC->mF);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetFloati_v: {
			GlCmdGetFloati_v* pCC = (GlCmdGetFloati_v*)pCmd;
			glGetFloati_v(pCC->mTarget, pCC->mIndex, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetDoublei_v: {
			GlCmdGetDoublei_v* pCC = (GlCmdGetDoublei_v*)pCmd;
			glGetDoublei_v(pCC->mTarget, pCC->mIndex, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DrawArraysInstancedBaseInstance: {
			GlCmdDrawArraysInstancedBaseInstance* pCC = (GlCmdDrawArraysInstancedBaseInstance*)pCmd;
			glDrawArraysInstancedBaseInstance(pCC->mMode, pCC->mFirst, pCC->mCount, pCC->mInstancecount, pCC->mBaseinstance);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DrawElementsInstancedBaseInstance: {
			GlCmdDrawElementsInstancedBaseInstance* pCC = (GlCmdDrawElementsInstancedBaseInstance*)pCmd;
			glDrawElementsInstancedBaseInstance(pCC->mMode, pCC->mCount, pCC->mType, pCC->mIndices, pCC->mInstancecount, pCC->mBaseinstance);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DrawElementsInstancedBaseVertexBaseInstance: {
			GlCmdDrawElementsInstancedBaseVertexBaseInstance* pCC = (GlCmdDrawElementsInstancedBaseVertexBaseInstance*)pCmd;
			glDrawElementsInstancedBaseVertexBaseInstance(pCC->mMode, pCC->mCount, pCC->mType, pCC->mIndices, pCC->mInstancecount, pCC->mBasevertex, pCC->mBaseinstance);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetInternalformativ: {
			GlCmdGetInternalformativ* pCC = (GlCmdGetInternalformativ*)pCmd;
			glGetInternalformativ(pCC->mTarget, pCC->mInternalformat, pCC->mPname, pCC->mBufsize, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetActiveAtomicCounterBufferiv: {
			GlCmdGetActiveAtomicCounterBufferiv* pCC = (GlCmdGetActiveAtomicCounterBufferiv*)pCmd;
			glGetActiveAtomicCounterBufferiv(pCC->mProgram, pCC->mBufferindex, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BindImageTexture: {
			GlCmdBindImageTexture* pCC = (GlCmdBindImageTexture*)pCmd;
			glBindImageTexture(pCC->mUnit, pCC->mTexture, pCC->mLevel, pCC->mLayered, pCC->mLayer, pCC->mAccess, pCC->mFormat);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MemoryBarrier: {
			GlCmdMemoryBarrier* pCC = (GlCmdMemoryBarrier*)pCmd;
			glMemoryBarrier(pCC->mBarriers);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TexStorage1D: {
			GlCmdTexStorage1D* pCC = (GlCmdTexStorage1D*)pCmd;
			glTexStorage1D(pCC->mTarget, pCC->mLevels, pCC->mInternalformat, pCC->mWidth);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TexStorage2D: {
			GlCmdTexStorage2D* pCC = (GlCmdTexStorage2D*)pCmd;
			glTexStorage2D(pCC->mTarget, pCC->mLevels, pCC->mInternalformat, pCC->mWidth, pCC->mHeight);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TexStorage3D: {
			GlCmdTexStorage3D* pCC = (GlCmdTexStorage3D*)pCmd;
			glTexStorage3D(pCC->mTarget, pCC->mLevels, pCC->mInternalformat, pCC->mWidth, pCC->mHeight, pCC->mDepth);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DrawTransformFeedbackInstanced: {
			GlCmdDrawTransformFeedbackInstanced* pCC = (GlCmdDrawTransformFeedbackInstanced*)pCmd;
			glDrawTransformFeedbackInstanced(pCC->mMode, pCC->mId, pCC->mInstancecount);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DrawTransformFeedbackStreamInstanced: {
			GlCmdDrawTransformFeedbackStreamInstanced* pCC = (GlCmdDrawTransformFeedbackStreamInstanced*)pCmd;
			glDrawTransformFeedbackStreamInstanced(pCC->mMode, pCC->mId, pCC->mStream, pCC->mInstancecount);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ClearBufferData: {
			GlCmdClearBufferData* pCC = (GlCmdClearBufferData*)pCmd;
			glClearBufferData(pCC->mTarget, pCC->mInternalformat, pCC->mFormat, pCC->mType, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ClearBufferSubData: {
			GlCmdClearBufferSubData* pCC = (GlCmdClearBufferSubData*)pCmd;
			glClearBufferSubData(pCC->mTarget, pCC->mInternalformat, pCC->mOffset, pCC->mSize, pCC->mFormat, pCC->mType, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DispatchCompute: {
			GlCmdDispatchCompute* pCC = (GlCmdDispatchCompute*)pCmd;
			glDispatchCompute(pCC->mNum_Groups_X, pCC->mNum_Groups_Y, pCC->mNum_Groups_Z);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DispatchComputeIndirect: {
			GlCmdDispatchComputeIndirect* pCC = (GlCmdDispatchComputeIndirect*)pCmd;
			glDispatchComputeIndirect(pCC->mIndirect);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CopyImageSubData: {
			GlCmdCopyImageSubData* pCC = (GlCmdCopyImageSubData*)pCmd;
			glCopyImageSubData(pCC->mSrcname, pCC->mSrctarget, pCC->mSrclevel, pCC->mSrcx, pCC->mSrcy, pCC->mSrcz, pCC->mDstname, pCC->mDsttarget, pCC->mDstlevel, pCC->mDstx, pCC->mDsty, pCC->mDstz, pCC->mSrcwidth, pCC->mSrcheight, pCC->mSrcdepth);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_FramebufferParameteri: {
			GlCmdFramebufferParameteri* pCC = (GlCmdFramebufferParameteri*)pCmd;
			glFramebufferParameteri(pCC->mTarget, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetFramebufferParameteriv: {
			GlCmdGetFramebufferParameteriv* pCC = (GlCmdGetFramebufferParameteriv*)pCmd;
			glGetFramebufferParameteriv(pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetInternalformati64v: {
			GlCmdGetInternalformati64v* pCC = (GlCmdGetInternalformati64v*)pCmd;
			glGetInternalformati64v(pCC->mTarget, pCC->mInternalformat, pCC->mPname, pCC->mBufsize, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_InvalidateTexSubImage: {
			GlCmdInvalidateTexSubImage* pCC = (GlCmdInvalidateTexSubImage*)pCmd;
			glInvalidateTexSubImage(pCC->mTexture, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mZoffset, pCC->mWidth, pCC->mHeight, pCC->mDepth);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_InvalidateTexImage: {
			GlCmdInvalidateTexImage* pCC = (GlCmdInvalidateTexImage*)pCmd;
			glInvalidateTexImage(pCC->mTexture, pCC->mLevel);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_InvalidateBufferSubData: {
			GlCmdInvalidateBufferSubData* pCC = (GlCmdInvalidateBufferSubData*)pCmd;
			glInvalidateBufferSubData(pCC->mBuffer, pCC->mOffset, pCC->mLength);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_InvalidateBufferData: {
			GlCmdInvalidateBufferData* pCC = (GlCmdInvalidateBufferData*)pCmd;
			glInvalidateBufferData(pCC->mBuffer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_InvalidateFramebuffer: {
			GlCmdInvalidateFramebuffer* pCC = (GlCmdInvalidateFramebuffer*)pCmd;
			glInvalidateFramebuffer(pCC->mTarget, pCC->mNumattachments, pCC->mAttachments);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_InvalidateSubFramebuffer: {
			GlCmdInvalidateSubFramebuffer* pCC = (GlCmdInvalidateSubFramebuffer*)pCmd;
			glInvalidateSubFramebuffer(pCC->mTarget, pCC->mNumattachments, pCC->mAttachments, pCC->mX, pCC->mY, pCC->mWidth, pCC->mHeight);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiDrawArraysIndirect: {
			GlCmdMultiDrawArraysIndirect* pCC = (GlCmdMultiDrawArraysIndirect*)pCmd;
			glMultiDrawArraysIndirect(pCC->mMode, pCC->mIndirect, pCC->mDrawcount, pCC->mStride);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiDrawElementsIndirect: {
			GlCmdMultiDrawElementsIndirect* pCC = (GlCmdMultiDrawElementsIndirect*)pCmd;
			glMultiDrawElementsIndirect(pCC->mMode, pCC->mType, pCC->mIndirect, pCC->mDrawcount, pCC->mStride);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetProgramInterfaceiv: {
			GlCmdGetProgramInterfaceiv* pCC = (GlCmdGetProgramInterfaceiv*)pCmd;
			glGetProgramInterfaceiv(pCC->mProgram, pCC->mPrograminterface, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetProgramResourceIndex: {
			GlCmdGetProgramResourceIndex* pCC = (GlCmdGetProgramResourceIndex*)pCmd;
			glGetProgramResourceIndex(pCC->mProgram, pCC->mPrograminterface, pCC->mName);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetProgramResourceName: {
			GlCmdGetProgramResourceName* pCC = (GlCmdGetProgramResourceName*)pCmd;
			glGetProgramResourceName(pCC->mProgram, pCC->mPrograminterface, pCC->mIndex, pCC->mBufsize, pCC->mLength, pCC->mName);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetProgramResourceiv: {
			GlCmdGetProgramResourceiv* pCC = (GlCmdGetProgramResourceiv*)pCmd;
			glGetProgramResourceiv(pCC->mProgram, pCC->mPrograminterface, pCC->mIndex, pCC->mPropcount, pCC->mProps, pCC->mBufsize, pCC->mLength, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetProgramResourceLocation: {
			GlCmdGetProgramResourceLocation* pCC = (GlCmdGetProgramResourceLocation*)pCmd;
			glGetProgramResourceLocation(pCC->mProgram, pCC->mPrograminterface, pCC->mName);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetProgramResourceLocationIndex: {
			GlCmdGetProgramResourceLocationIndex* pCC = (GlCmdGetProgramResourceLocationIndex*)pCmd;
			glGetProgramResourceLocationIndex(pCC->mProgram, pCC->mPrograminterface, pCC->mName);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ShaderStorageBlockBinding: {
			GlCmdShaderStorageBlockBinding* pCC = (GlCmdShaderStorageBlockBinding*)pCmd;
			glShaderStorageBlockBinding(pCC->mProgram, pCC->mStorageblockindex, pCC->mStorageblockbinding);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TexBufferRange: {
			GlCmdTexBufferRange* pCC = (GlCmdTexBufferRange*)pCmd;
			glTexBufferRange(pCC->mTarget, pCC->mInternalformat, pCC->mBuffer, pCC->mOffset, pCC->mSize);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TexStorage2DMultisample: {
			GlCmdTexStorage2DMultisample* pCC = (GlCmdTexStorage2DMultisample*)pCmd;
			glTexStorage2DMultisample(pCC->mTarget, pCC->mSamples, pCC->mInternalformat, pCC->mWidth, pCC->mHeight, pCC->mFixedsamplelocations);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TexStorage3DMultisample: {
			GlCmdTexStorage3DMultisample* pCC = (GlCmdTexStorage3DMultisample*)pCmd;
			glTexStorage3DMultisample(pCC->mTarget, pCC->mSamples, pCC->mInternalformat, pCC->mWidth, pCC->mHeight, pCC->mDepth, pCC->mFixedsamplelocations);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureView: {
			GlCmdTextureView* pCC = (GlCmdTextureView*)pCmd;
			glTextureView(pCC->mTexture, pCC->mTarget, pCC->mOrigtexture, pCC->mInternalformat, pCC->mMinlevel, pCC->mNumlevels, pCC->mMinlayer, pCC->mNumlayers);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BindVertexBuffer: {
			GlCmdBindVertexBuffer* pCC = (GlCmdBindVertexBuffer*)pCmd;
			glBindVertexBuffer(pCC->mBindingindex, pCC->mBuffer, pCC->mOffset, pCC->mStride);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribFormat: {
			GlCmdVertexAttribFormat* pCC = (GlCmdVertexAttribFormat*)pCmd;
			glVertexAttribFormat(pCC->mAttribindex, pCC->mSize, pCC->mType, pCC->mNormalized, pCC->mRelativeoffset);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribIFormat: {
			GlCmdVertexAttribIFormat* pCC = (GlCmdVertexAttribIFormat*)pCmd;
			glVertexAttribIFormat(pCC->mAttribindex, pCC->mSize, pCC->mType, pCC->mRelativeoffset);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribLFormat: {
			GlCmdVertexAttribLFormat* pCC = (GlCmdVertexAttribLFormat*)pCmd;
			glVertexAttribLFormat(pCC->mAttribindex, pCC->mSize, pCC->mType, pCC->mRelativeoffset);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribBinding: {
			GlCmdVertexAttribBinding* pCC = (GlCmdVertexAttribBinding*)pCmd;
			glVertexAttribBinding(pCC->mAttribindex, pCC->mBindingindex);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexBindingDivisor: {
			GlCmdVertexBindingDivisor* pCC = (GlCmdVertexBindingDivisor*)pCmd;
			glVertexBindingDivisor(pCC->mBindingindex, pCC->mDivisor);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DebugMessageControl: {
			GlCmdDebugMessageControl* pCC = (GlCmdDebugMessageControl*)pCmd;
			glDebugMessageControl(pCC->mSource, pCC->mType, pCC->mSeverity, pCC->mCount, pCC->mIds, pCC->mEnabled);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DebugMessageInsert: {
			GlCmdDebugMessageInsert* pCC = (GlCmdDebugMessageInsert*)pCmd;
			glDebugMessageInsert(pCC->mSource, pCC->mType, pCC->mId, pCC->mSeverity, pCC->mLength, pCC->mBuf);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DebugMessageCallback: {
			GlCmdDebugMessageCallback* pCC = (GlCmdDebugMessageCallback*)pCmd;
			glDebugMessageCallback(pCC->mCallback, pCC->mUserparam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetDebugMessageLog: {
			GlCmdGetDebugMessageLog* pCC = (GlCmdGetDebugMessageLog*)pCmd;
			glGetDebugMessageLog(pCC->mCount, pCC->mBufsize, pCC->mSources, pCC->mTypes, pCC->mIds, pCC->mSeverities, pCC->mLengths, pCC->mMessagelog);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_PushDebugGroup: {
			GlCmdPushDebugGroup* pCC = (GlCmdPushDebugGroup*)pCmd;
			glPushDebugGroup(pCC->mSource, pCC->mId, pCC->mLength, pCC->mMessage);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_PopDebugGroup: {
			GlCmdPopDebugGroup* pCC = (GlCmdPopDebugGroup*)pCmd;
			glPopDebugGroup();
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ObjectLabel: {
			GlCmdObjectLabel* pCC = (GlCmdObjectLabel*)pCmd;
			glObjectLabel(pCC->mIdentifier, pCC->mName, pCC->mLength, pCC->mLabel);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetObjectLabel: {
			GlCmdGetObjectLabel* pCC = (GlCmdGetObjectLabel*)pCmd;
			glGetObjectLabel(pCC->mIdentifier, pCC->mName, pCC->mBufsize, pCC->mLength, pCC->mLabel);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ObjectPtrLabel: {
			GlCmdObjectPtrLabel* pCC = (GlCmdObjectPtrLabel*)pCmd;
			glObjectPtrLabel(pCC->mPtr, pCC->mLength, pCC->mLabel);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetObjectPtrLabel: {
			GlCmdGetObjectPtrLabel* pCC = (GlCmdGetObjectPtrLabel*)pCmd;
			glGetObjectPtrLabel(pCC->mPtr, pCC->mBufsize, pCC->mLength, pCC->mLabel);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BufferStorage: {
			GlCmdBufferStorage* pCC = (GlCmdBufferStorage*)pCmd;
			glBufferStorage(pCC->mTarget, pCC->mSize, pCC->mData, pCC->mFlags);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ClearTexImage: {
			GlCmdClearTexImage* pCC = (GlCmdClearTexImage*)pCmd;
			glClearTexImage(pCC->mTexture, pCC->mLevel, pCC->mFormat, pCC->mType, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ClearTexSubImage: {
			GlCmdClearTexSubImage* pCC = (GlCmdClearTexSubImage*)pCmd;
			glClearTexSubImage(pCC->mTexture, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mZoffset, pCC->mWidth, pCC->mHeight, pCC->mDepth, pCC->mFormat, pCC->mType, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BindBuffersBase: {
			GlCmdBindBuffersBase* pCC = (GlCmdBindBuffersBase*)pCmd;
			glBindBuffersBase(pCC->mTarget, pCC->mFirst, pCC->mCount, pCC->mBuffers);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BindBuffersRange: {
			GlCmdBindBuffersRange* pCC = (GlCmdBindBuffersRange*)pCmd;
			glBindBuffersRange(pCC->mTarget, pCC->mFirst, pCC->mCount, pCC->mBuffers, pCC->mOffsets, pCC->mSizes);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BindTextures: {
			GlCmdBindTextures* pCC = (GlCmdBindTextures*)pCmd;
			glBindTextures(pCC->mFirst, pCC->mCount, pCC->mTextures);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BindSamplers: {
			GlCmdBindSamplers* pCC = (GlCmdBindSamplers*)pCmd;
			glBindSamplers(pCC->mFirst, pCC->mCount, pCC->mSamplers);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BindImageTextures: {
			GlCmdBindImageTextures* pCC = (GlCmdBindImageTextures*)pCmd;
			glBindImageTextures(pCC->mFirst, pCC->mCount, pCC->mTextures);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BindVertexBuffers: {
			GlCmdBindVertexBuffers* pCC = (GlCmdBindVertexBuffers*)pCmd;
			glBindVertexBuffers(pCC->mFirst, pCC->mCount, pCC->mBuffers, pCC->mOffsets, pCC->mStrides);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ClipControl: {
			GlCmdClipControl* pCC = (GlCmdClipControl*)pCmd;
			glClipControl(pCC->mOrigin, pCC->mDepth);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CreateTransformFeedbacks: {
			GlCmdCreateTransformFeedbacks* pCC = (GlCmdCreateTransformFeedbacks*)pCmd;
			glCreateTransformFeedbacks(pCC->mN, pCC->mIds);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TransformFeedbackBufferBase: {
			GlCmdTransformFeedbackBufferBase* pCC = (GlCmdTransformFeedbackBufferBase*)pCmd;
			glTransformFeedbackBufferBase(pCC->mXfb, pCC->mIndex, pCC->mBuffer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TransformFeedbackBufferRange: {
			GlCmdTransformFeedbackBufferRange* pCC = (GlCmdTransformFeedbackBufferRange*)pCmd;
			glTransformFeedbackBufferRange(pCC->mXfb, pCC->mIndex, pCC->mBuffer, pCC->mOffset, pCC->mSize);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetTransformFeedbackiv: {
			GlCmdGetTransformFeedbackiv* pCC = (GlCmdGetTransformFeedbackiv*)pCmd;
			glGetTransformFeedbackiv(pCC->mXfb, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetTransformFeedbacki_v: {
			GlCmdGetTransformFeedbacki_v* pCC = (GlCmdGetTransformFeedbacki_v*)pCmd;
			glGetTransformFeedbacki_v(pCC->mXfb, pCC->mPname, pCC->mIndex, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetTransformFeedbacki64_v: {
			GlCmdGetTransformFeedbacki64_v* pCC = (GlCmdGetTransformFeedbacki64_v*)pCmd;
			glGetTransformFeedbacki64_v(pCC->mXfb, pCC->mPname, pCC->mIndex, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CreateBuffers: {
			GlCmdCreateBuffers* pCC = (GlCmdCreateBuffers*)pCmd;
			glCreateBuffers(pCC->mN, pCC->mBuffers);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedBufferStorage: {
			GlCmdNamedBufferStorage* pCC = (GlCmdNamedBufferStorage*)pCmd;
			glNamedBufferStorage(pCC->mBuffer, pCC->mSize, pCC->mData, pCC->mFlags);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedBufferData: {
			GlCmdNamedBufferData* pCC = (GlCmdNamedBufferData*)pCmd;
			glNamedBufferData(pCC->mBuffer, pCC->mSize, pCC->mData, pCC->mUsage);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedBufferSubData: {
			GlCmdNamedBufferSubData* pCC = (GlCmdNamedBufferSubData*)pCmd;
			glNamedBufferSubData(pCC->mBuffer, pCC->mOffset, pCC->mSize, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CopyNamedBufferSubData: {
			GlCmdCopyNamedBufferSubData* pCC = (GlCmdCopyNamedBufferSubData*)pCmd;
			glCopyNamedBufferSubData(pCC->mReadbuffer, pCC->mWritebuffer, pCC->mReadoffset, pCC->mWriteoffset, pCC->mSize);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ClearNamedBufferData: {
			GlCmdClearNamedBufferData* pCC = (GlCmdClearNamedBufferData*)pCmd;
			glClearNamedBufferData(pCC->mBuffer, pCC->mInternalformat, pCC->mFormat, pCC->mType, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ClearNamedBufferSubData: {
			GlCmdClearNamedBufferSubData* pCC = (GlCmdClearNamedBufferSubData*)pCmd;
			glClearNamedBufferSubData(pCC->mBuffer, pCC->mInternalformat, pCC->mOffset, pCC->mSize, pCC->mFormat, pCC->mType, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MapNamedBuffer: {
			GlCmdMapNamedBuffer* pCC = (GlCmdMapNamedBuffer*)pCmd;
			glMapNamedBuffer(pCC->mBuffer, pCC->mAccess);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MapNamedBufferRange: {
			GlCmdMapNamedBufferRange* pCC = (GlCmdMapNamedBufferRange*)pCmd;
			glMapNamedBufferRange(pCC->mBuffer, pCC->mOffset, pCC->mLength, pCC->mAccess);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_UnmapNamedBuffer: {
			GlCmdUnmapNamedBuffer* pCC = (GlCmdUnmapNamedBuffer*)pCmd;
			glUnmapNamedBuffer(pCC->mBuffer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_FlushMappedNamedBufferRange: {
			GlCmdFlushMappedNamedBufferRange* pCC = (GlCmdFlushMappedNamedBufferRange*)pCmd;
			glFlushMappedNamedBufferRange(pCC->mBuffer, pCC->mOffset, pCC->mLength);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetNamedBufferParameteriv: {
			GlCmdGetNamedBufferParameteriv* pCC = (GlCmdGetNamedBufferParameteriv*)pCmd;
			glGetNamedBufferParameteriv(pCC->mBuffer, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetNamedBufferParameteri64v: {
			GlCmdGetNamedBufferParameteri64v* pCC = (GlCmdGetNamedBufferParameteri64v*)pCmd;
			glGetNamedBufferParameteri64v(pCC->mBuffer, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetNamedBufferPointerv: {
			GlCmdGetNamedBufferPointerv* pCC = (GlCmdGetNamedBufferPointerv*)pCmd;
			glGetNamedBufferPointerv(pCC->mBuffer, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetNamedBufferSubData: {
			GlCmdGetNamedBufferSubData* pCC = (GlCmdGetNamedBufferSubData*)pCmd;
			glGetNamedBufferSubData(pCC->mBuffer, pCC->mOffset, pCC->mSize, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CreateFramebuffers: {
			GlCmdCreateFramebuffers* pCC = (GlCmdCreateFramebuffers*)pCmd;
			glCreateFramebuffers(pCC->mN, pCC->mFramebuffers);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedFramebufferRenderbuffer: {
			GlCmdNamedFramebufferRenderbuffer* pCC = (GlCmdNamedFramebufferRenderbuffer*)pCmd;
			glNamedFramebufferRenderbuffer(pCC->mFramebuffer, pCC->mAttachment, pCC->mRenderbuffertarget, pCC->mRenderbuffer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedFramebufferParameteri: {
			GlCmdNamedFramebufferParameteri* pCC = (GlCmdNamedFramebufferParameteri*)pCmd;
			glNamedFramebufferParameteri(pCC->mFramebuffer, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedFramebufferTexture: {
			GlCmdNamedFramebufferTexture* pCC = (GlCmdNamedFramebufferTexture*)pCmd;
			glNamedFramebufferTexture(pCC->mFramebuffer, pCC->mAttachment, pCC->mTexture, pCC->mLevel);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedFramebufferTextureLayer: {
			GlCmdNamedFramebufferTextureLayer* pCC = (GlCmdNamedFramebufferTextureLayer*)pCmd;
			glNamedFramebufferTextureLayer(pCC->mFramebuffer, pCC->mAttachment, pCC->mTexture, pCC->mLevel, pCC->mLayer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedFramebufferDrawBuffer: {
			GlCmdNamedFramebufferDrawBuffer* pCC = (GlCmdNamedFramebufferDrawBuffer*)pCmd;
			glNamedFramebufferDrawBuffer(pCC->mFramebuffer, pCC->mBuf);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedFramebufferDrawBuffers: {
			GlCmdNamedFramebufferDrawBuffers* pCC = (GlCmdNamedFramebufferDrawBuffers*)pCmd;
			glNamedFramebufferDrawBuffers(pCC->mFramebuffer, pCC->mN, pCC->mBufs);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedFramebufferReadBuffer: {
			GlCmdNamedFramebufferReadBuffer* pCC = (GlCmdNamedFramebufferReadBuffer*)pCmd;
			glNamedFramebufferReadBuffer(pCC->mFramebuffer, pCC->mSrc);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_InvalidateNamedFramebufferData: {
			GlCmdInvalidateNamedFramebufferData* pCC = (GlCmdInvalidateNamedFramebufferData*)pCmd;
			glInvalidateNamedFramebufferData(pCC->mFramebuffer, pCC->mNumattachments, pCC->mAttachments);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_InvalidateNamedFramebufferSubData: {
			GlCmdInvalidateNamedFramebufferSubData* pCC = (GlCmdInvalidateNamedFramebufferSubData*)pCmd;
			glInvalidateNamedFramebufferSubData(pCC->mFramebuffer, pCC->mNumattachments, pCC->mAttachments, pCC->mX, pCC->mY, pCC->mWidth, pCC->mHeight);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ClearNamedFramebufferiv: {
			GlCmdClearNamedFramebufferiv* pCC = (GlCmdClearNamedFramebufferiv*)pCmd;
			glClearNamedFramebufferiv(pCC->mFramebuffer, pCC->mBuffer, pCC->mDrawbuffer, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ClearNamedFramebufferuiv: {
			GlCmdClearNamedFramebufferuiv* pCC = (GlCmdClearNamedFramebufferuiv*)pCmd;
			glClearNamedFramebufferuiv(pCC->mFramebuffer, pCC->mBuffer, pCC->mDrawbuffer, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ClearNamedFramebufferfv: {
			GlCmdClearNamedFramebufferfv* pCC = (GlCmdClearNamedFramebufferfv*)pCmd;
			glClearNamedFramebufferfv(pCC->mFramebuffer, pCC->mBuffer, pCC->mDrawbuffer, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ClearNamedFramebufferfi: {
			GlCmdClearNamedFramebufferfi* pCC = (GlCmdClearNamedFramebufferfi*)pCmd;
			glClearNamedFramebufferfi(pCC->mFramebuffer, pCC->mBuffer, pCC->mDrawbuffer, pCC->mDepth, pCC->mStencil);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BlitNamedFramebuffer: {
			GlCmdBlitNamedFramebuffer* pCC = (GlCmdBlitNamedFramebuffer*)pCmd;
			glBlitNamedFramebuffer(pCC->mReadframebuffer, pCC->mDrawframebuffer, pCC->mSrcx0, pCC->mSrcy0, pCC->mSrcx1, pCC->mSrcy1, pCC->mDstx0, pCC->mDsty0, pCC->mDstx1, pCC->mDsty1, pCC->mMask, pCC->mFilter);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CheckNamedFramebufferStatus: {
			GlCmdCheckNamedFramebufferStatus* pCC = (GlCmdCheckNamedFramebufferStatus*)pCmd;
			glCheckNamedFramebufferStatus(pCC->mFramebuffer, pCC->mTarget);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetNamedFramebufferParameteriv: {
			GlCmdGetNamedFramebufferParameteriv* pCC = (GlCmdGetNamedFramebufferParameteriv*)pCmd;
			glGetNamedFramebufferParameteriv(pCC->mFramebuffer, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetNamedFramebufferAttachmentParameteriv: {
			GlCmdGetNamedFramebufferAttachmentParameteriv* pCC = (GlCmdGetNamedFramebufferAttachmentParameteriv*)pCmd;
			glGetNamedFramebufferAttachmentParameteriv(pCC->mFramebuffer, pCC->mAttachment, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CreateRenderbuffers: {
			GlCmdCreateRenderbuffers* pCC = (GlCmdCreateRenderbuffers*)pCmd;
			glCreateRenderbuffers(pCC->mN, pCC->mRenderbuffers);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedRenderbufferStorage: {
			GlCmdNamedRenderbufferStorage* pCC = (GlCmdNamedRenderbufferStorage*)pCmd;
			glNamedRenderbufferStorage(pCC->mRenderbuffer, pCC->mInternalformat, pCC->mWidth, pCC->mHeight);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedRenderbufferStorageMultisample: {
			GlCmdNamedRenderbufferStorageMultisample* pCC = (GlCmdNamedRenderbufferStorageMultisample*)pCmd;
			glNamedRenderbufferStorageMultisample(pCC->mRenderbuffer, pCC->mSamples, pCC->mInternalformat, pCC->mWidth, pCC->mHeight);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetNamedRenderbufferParameteriv: {
			GlCmdGetNamedRenderbufferParameteriv* pCC = (GlCmdGetNamedRenderbufferParameteriv*)pCmd;
			glGetNamedRenderbufferParameteriv(pCC->mRenderbuffer, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CreateTextures: {
			GlCmdCreateTextures* pCC = (GlCmdCreateTextures*)pCmd;
			glCreateTextures(pCC->mTarget, pCC->mN, pCC->mTextures);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureBuffer: {
			GlCmdTextureBuffer* pCC = (GlCmdTextureBuffer*)pCmd;
			glTextureBuffer(pCC->mTexture, pCC->mInternalformat, pCC->mBuffer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureBufferRange: {
			GlCmdTextureBufferRange* pCC = (GlCmdTextureBufferRange*)pCmd;
			glTextureBufferRange(pCC->mTexture, pCC->mInternalformat, pCC->mBuffer, pCC->mOffset, pCC->mSize);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureStorage1D: {
			GlCmdTextureStorage1D* pCC = (GlCmdTextureStorage1D*)pCmd;
			glTextureStorage1D(pCC->mTexture, pCC->mLevels, pCC->mInternalformat, pCC->mWidth);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureStorage2D: {
			GlCmdTextureStorage2D* pCC = (GlCmdTextureStorage2D*)pCmd;
			glTextureStorage2D(pCC->mTexture, pCC->mLevels, pCC->mInternalformat, pCC->mWidth, pCC->mHeight);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureStorage3D: {
			GlCmdTextureStorage3D* pCC = (GlCmdTextureStorage3D*)pCmd;
			glTextureStorage3D(pCC->mTexture, pCC->mLevels, pCC->mInternalformat, pCC->mWidth, pCC->mHeight, pCC->mDepth);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureStorage2DMultisample: {
			GlCmdTextureStorage2DMultisample* pCC = (GlCmdTextureStorage2DMultisample*)pCmd;
			glTextureStorage2DMultisample(pCC->mTexture, pCC->mSamples, pCC->mInternalformat, pCC->mWidth, pCC->mHeight, pCC->mFixedsamplelocations);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureStorage3DMultisample: {
			GlCmdTextureStorage3DMultisample* pCC = (GlCmdTextureStorage3DMultisample*)pCmd;
			glTextureStorage3DMultisample(pCC->mTexture, pCC->mSamples, pCC->mInternalformat, pCC->mWidth, pCC->mHeight, pCC->mDepth, pCC->mFixedsamplelocations);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureSubImage1D: {
			GlCmdTextureSubImage1D* pCC = (GlCmdTextureSubImage1D*)pCmd;
			glTextureSubImage1D(pCC->mTexture, pCC->mLevel, pCC->mXoffset, pCC->mWidth, pCC->mFormat, pCC->mType, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureSubImage2D: {
			GlCmdTextureSubImage2D* pCC = (GlCmdTextureSubImage2D*)pCmd;
			glTextureSubImage2D(pCC->mTexture, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mWidth, pCC->mHeight, pCC->mFormat, pCC->mType, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureSubImage3D: {
			GlCmdTextureSubImage3D* pCC = (GlCmdTextureSubImage3D*)pCmd;
			glTextureSubImage3D(pCC->mTexture, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mZoffset, pCC->mWidth, pCC->mHeight, pCC->mDepth, pCC->mFormat, pCC->mType, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CompressedTextureSubImage1D: {
			GlCmdCompressedTextureSubImage1D* pCC = (GlCmdCompressedTextureSubImage1D*)pCmd;
			glCompressedTextureSubImage1D(pCC->mTexture, pCC->mLevel, pCC->mXoffset, pCC->mWidth, pCC->mFormat, pCC->mImagesize, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CompressedTextureSubImage2D: {
			GlCmdCompressedTextureSubImage2D* pCC = (GlCmdCompressedTextureSubImage2D*)pCmd;
			glCompressedTextureSubImage2D(pCC->mTexture, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mWidth, pCC->mHeight, pCC->mFormat, pCC->mImagesize, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CompressedTextureSubImage3D: {
			GlCmdCompressedTextureSubImage3D* pCC = (GlCmdCompressedTextureSubImage3D*)pCmd;
			glCompressedTextureSubImage3D(pCC->mTexture, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mZoffset, pCC->mWidth, pCC->mHeight, pCC->mDepth, pCC->mFormat, pCC->mImagesize, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CopyTextureSubImage1D: {
			GlCmdCopyTextureSubImage1D* pCC = (GlCmdCopyTextureSubImage1D*)pCmd;
			glCopyTextureSubImage1D(pCC->mTexture, pCC->mLevel, pCC->mXoffset, pCC->mX, pCC->mY, pCC->mWidth);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CopyTextureSubImage2D: {
			GlCmdCopyTextureSubImage2D* pCC = (GlCmdCopyTextureSubImage2D*)pCmd;
			glCopyTextureSubImage2D(pCC->mTexture, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mX, pCC->mY, pCC->mWidth, pCC->mHeight);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CopyTextureSubImage3D: {
			GlCmdCopyTextureSubImage3D* pCC = (GlCmdCopyTextureSubImage3D*)pCmd;
			glCopyTextureSubImage3D(pCC->mTexture, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mZoffset, pCC->mX, pCC->mY, pCC->mWidth, pCC->mHeight);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureParameterf: {
			GlCmdTextureParameterf* pCC = (GlCmdTextureParameterf*)pCmd;
			glTextureParameterf(pCC->mTexture, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureParameterfv: {
			GlCmdTextureParameterfv* pCC = (GlCmdTextureParameterfv*)pCmd;
			glTextureParameterfv(pCC->mTexture, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureParameteri: {
			GlCmdTextureParameteri* pCC = (GlCmdTextureParameteri*)pCmd;
			glTextureParameteri(pCC->mTexture, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureParameterIiv: {
			GlCmdTextureParameterIiv* pCC = (GlCmdTextureParameterIiv*)pCmd;
			glTextureParameterIiv(pCC->mTexture, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureParameterIuiv: {
			GlCmdTextureParameterIuiv* pCC = (GlCmdTextureParameterIuiv*)pCmd;
			glTextureParameterIuiv(pCC->mTexture, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureParameteriv: {
			GlCmdTextureParameteriv* pCC = (GlCmdTextureParameteriv*)pCmd;
			glTextureParameteriv(pCC->mTexture, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GenerateTextureMipmap: {
			GlCmdGenerateTextureMipmap* pCC = (GlCmdGenerateTextureMipmap*)pCmd;
			glGenerateTextureMipmap(pCC->mTexture);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BindTextureUnit: {
			GlCmdBindTextureUnit* pCC = (GlCmdBindTextureUnit*)pCmd;
			glBindTextureUnit(pCC->mUnit, pCC->mTexture);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetTextureImage: {
			GlCmdGetTextureImage* pCC = (GlCmdGetTextureImage*)pCmd;
			glGetTextureImage(pCC->mTexture, pCC->mLevel, pCC->mFormat, pCC->mType, pCC->mBufsize, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetCompressedTextureImage: {
			GlCmdGetCompressedTextureImage* pCC = (GlCmdGetCompressedTextureImage*)pCmd;
			glGetCompressedTextureImage(pCC->mTexture, pCC->mLevel, pCC->mBufsize, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetTextureLevelParameterfv: {
			GlCmdGetTextureLevelParameterfv* pCC = (GlCmdGetTextureLevelParameterfv*)pCmd;
			glGetTextureLevelParameterfv(pCC->mTexture, pCC->mLevel, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetTextureLevelParameteriv: {
			GlCmdGetTextureLevelParameteriv* pCC = (GlCmdGetTextureLevelParameteriv*)pCmd;
			glGetTextureLevelParameteriv(pCC->mTexture, pCC->mLevel, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetTextureParameterfv: {
			GlCmdGetTextureParameterfv* pCC = (GlCmdGetTextureParameterfv*)pCmd;
			glGetTextureParameterfv(pCC->mTexture, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetTextureParameterIiv: {
			GlCmdGetTextureParameterIiv* pCC = (GlCmdGetTextureParameterIiv*)pCmd;
			glGetTextureParameterIiv(pCC->mTexture, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetTextureParameterIuiv: {
			GlCmdGetTextureParameterIuiv* pCC = (GlCmdGetTextureParameterIuiv*)pCmd;
			glGetTextureParameterIuiv(pCC->mTexture, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetTextureParameteriv: {
			GlCmdGetTextureParameteriv* pCC = (GlCmdGetTextureParameteriv*)pCmd;
			glGetTextureParameteriv(pCC->mTexture, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CreateVertexArrays: {
			GlCmdCreateVertexArrays* pCC = (GlCmdCreateVertexArrays*)pCmd;
			glCreateVertexArrays(pCC->mN, pCC->mArrays);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DisableVertexArrayAttrib: {
			GlCmdDisableVertexArrayAttrib* pCC = (GlCmdDisableVertexArrayAttrib*)pCmd;
			glDisableVertexArrayAttrib(pCC->mVaobj, pCC->mIndex);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_EnableVertexArrayAttrib: {
			GlCmdEnableVertexArrayAttrib* pCC = (GlCmdEnableVertexArrayAttrib*)pCmd;
			glEnableVertexArrayAttrib(pCC->mVaobj, pCC->mIndex);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexArrayElementBuffer: {
			GlCmdVertexArrayElementBuffer* pCC = (GlCmdVertexArrayElementBuffer*)pCmd;
			glVertexArrayElementBuffer(pCC->mVaobj, pCC->mBuffer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexArrayVertexBuffer: {
			GlCmdVertexArrayVertexBuffer* pCC = (GlCmdVertexArrayVertexBuffer*)pCmd;
			glVertexArrayVertexBuffer(pCC->mVaobj, pCC->mBindingindex, pCC->mBuffer, pCC->mOffset, pCC->mStride);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexArrayVertexBuffers: {
			GlCmdVertexArrayVertexBuffers* pCC = (GlCmdVertexArrayVertexBuffers*)pCmd;
			glVertexArrayVertexBuffers(pCC->mVaobj, pCC->mFirst, pCC->mCount, pCC->mBuffers, pCC->mOffsets, pCC->mStrides);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexArrayAttribBinding: {
			GlCmdVertexArrayAttribBinding* pCC = (GlCmdVertexArrayAttribBinding*)pCmd;
			glVertexArrayAttribBinding(pCC->mVaobj, pCC->mAttribindex, pCC->mBindingindex);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexArrayAttribFormat: {
			GlCmdVertexArrayAttribFormat* pCC = (GlCmdVertexArrayAttribFormat*)pCmd;
			glVertexArrayAttribFormat(pCC->mVaobj, pCC->mAttribindex, pCC->mSize, pCC->mType, pCC->mNormalized, pCC->mRelativeoffset);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexArrayAttribIFormat: {
			GlCmdVertexArrayAttribIFormat* pCC = (GlCmdVertexArrayAttribIFormat*)pCmd;
			glVertexArrayAttribIFormat(pCC->mVaobj, pCC->mAttribindex, pCC->mSize, pCC->mType, pCC->mRelativeoffset);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexArrayAttribLFormat: {
			GlCmdVertexArrayAttribLFormat* pCC = (GlCmdVertexArrayAttribLFormat*)pCmd;
			glVertexArrayAttribLFormat(pCC->mVaobj, pCC->mAttribindex, pCC->mSize, pCC->mType, pCC->mRelativeoffset);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexArrayBindingDivisor: {
			GlCmdVertexArrayBindingDivisor* pCC = (GlCmdVertexArrayBindingDivisor*)pCmd;
			glVertexArrayBindingDivisor(pCC->mVaobj, pCC->mBindingindex, pCC->mDivisor);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetVertexArrayiv: {
			GlCmdGetVertexArrayiv* pCC = (GlCmdGetVertexArrayiv*)pCmd;
			glGetVertexArrayiv(pCC->mVaobj, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetVertexArrayIndexediv: {
			GlCmdGetVertexArrayIndexediv* pCC = (GlCmdGetVertexArrayIndexediv*)pCmd;
			glGetVertexArrayIndexediv(pCC->mVaobj, pCC->mIndex, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetVertexArrayIndexed64iv: {
			GlCmdGetVertexArrayIndexed64iv* pCC = (GlCmdGetVertexArrayIndexed64iv*)pCmd;
			glGetVertexArrayIndexed64iv(pCC->mVaobj, pCC->mIndex, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CreateSamplers: {
			GlCmdCreateSamplers* pCC = (GlCmdCreateSamplers*)pCmd;
			glCreateSamplers(pCC->mN, pCC->mSamplers);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CreateProgramPipelines: {
			GlCmdCreateProgramPipelines* pCC = (GlCmdCreateProgramPipelines*)pCmd;
			glCreateProgramPipelines(pCC->mN, pCC->mPipelines);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CreateQueries: {
			GlCmdCreateQueries* pCC = (GlCmdCreateQueries*)pCmd;
			glCreateQueries(pCC->mTarget, pCC->mN, pCC->mIds);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetQueryBufferObjecti64v: {
			GlCmdGetQueryBufferObjecti64v* pCC = (GlCmdGetQueryBufferObjecti64v*)pCmd;
			glGetQueryBufferObjecti64v(pCC->mId, pCC->mBuffer, pCC->mPname, pCC->mOffset);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetQueryBufferObjectiv: {
			GlCmdGetQueryBufferObjectiv* pCC = (GlCmdGetQueryBufferObjectiv*)pCmd;
			glGetQueryBufferObjectiv(pCC->mId, pCC->mBuffer, pCC->mPname, pCC->mOffset);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetQueryBufferObjectui64v: {
			GlCmdGetQueryBufferObjectui64v* pCC = (GlCmdGetQueryBufferObjectui64v*)pCmd;
			glGetQueryBufferObjectui64v(pCC->mId, pCC->mBuffer, pCC->mPname, pCC->mOffset);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetQueryBufferObjectuiv: {
			GlCmdGetQueryBufferObjectuiv* pCC = (GlCmdGetQueryBufferObjectuiv*)pCmd;
			glGetQueryBufferObjectuiv(pCC->mId, pCC->mBuffer, pCC->mPname, pCC->mOffset);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MemoryBarrierByRegion: {
			GlCmdMemoryBarrierByRegion* pCC = (GlCmdMemoryBarrierByRegion*)pCmd;
			glMemoryBarrierByRegion(pCC->mBarriers);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetTextureSubImage: {
			GlCmdGetTextureSubImage* pCC = (GlCmdGetTextureSubImage*)pCmd;
			glGetTextureSubImage(pCC->mTexture, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mZoffset, pCC->mWidth, pCC->mHeight, pCC->mDepth, pCC->mFormat, pCC->mType, pCC->mBufsize, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetCompressedTextureSubImage: {
			GlCmdGetCompressedTextureSubImage* pCC = (GlCmdGetCompressedTextureSubImage*)pCmd;
			glGetCompressedTextureSubImage(pCC->mTexture, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mZoffset, pCC->mWidth, pCC->mHeight, pCC->mDepth, pCC->mBufsize, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetGraphicsResetStatus: {
			GlCmdGetGraphicsResetStatus* pCC = (GlCmdGetGraphicsResetStatus*)pCmd;
			glGetGraphicsResetStatus();
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetnCompressedTexImage: {
			GlCmdGetnCompressedTexImage* pCC = (GlCmdGetnCompressedTexImage*)pCmd;
			glGetnCompressedTexImage(pCC->mTarget, pCC->mLod, pCC->mBufsize, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetnTexImage: {
			GlCmdGetnTexImage* pCC = (GlCmdGetnTexImage*)pCmd;
			glGetnTexImage(pCC->mTarget, pCC->mLevel, pCC->mFormat, pCC->mType, pCC->mBufsize, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetnUniformdv: {
			GlCmdGetnUniformdv* pCC = (GlCmdGetnUniformdv*)pCmd;
			glGetnUniformdv(pCC->mProgram, pCC->mLocation, pCC->mBufsize, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetnUniformfv: {
			GlCmdGetnUniformfv* pCC = (GlCmdGetnUniformfv*)pCmd;
			glGetnUniformfv(pCC->mProgram, pCC->mLocation, pCC->mBufsize, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetnUniformiv: {
			GlCmdGetnUniformiv* pCC = (GlCmdGetnUniformiv*)pCmd;
			glGetnUniformiv(pCC->mProgram, pCC->mLocation, pCC->mBufsize, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetnUniformuiv: {
			GlCmdGetnUniformuiv* pCC = (GlCmdGetnUniformuiv*)pCmd;
			glGetnUniformuiv(pCC->mProgram, pCC->mLocation, pCC->mBufsize, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ReadnPixels: {
			GlCmdReadnPixels* pCC = (GlCmdReadnPixels*)pCmd;
			glReadnPixels(pCC->mX, pCC->mY, pCC->mWidth, pCC->mHeight, pCC->mFormat, pCC->mType, pCC->mBufsize, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureBarrier: {
			GlCmdTextureBarrier* pCC = (GlCmdTextureBarrier*)pCmd;
			glTextureBarrier();
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_SpecializeShader: {
			GlCmdSpecializeShader* pCC = (GlCmdSpecializeShader*)pCmd;
			glSpecializeShader(pCC->mShader, pCC->mPentrypoint, pCC->mNumspecializationconstants, pCC->mPconstantindex, pCC->mPconstantvalue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiDrawArraysIndirectCount: {
			GlCmdMultiDrawArraysIndirectCount* pCC = (GlCmdMultiDrawArraysIndirectCount*)pCmd;
			glMultiDrawArraysIndirectCount(pCC->mMode, pCC->mIndirect, pCC->mDrawcount, pCC->mMaxdrawcount, pCC->mStride);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiDrawElementsIndirectCount: {
			GlCmdMultiDrawElementsIndirectCount* pCC = (GlCmdMultiDrawElementsIndirectCount*)pCmd;
			glMultiDrawElementsIndirectCount(pCC->mMode, pCC->mType, pCC->mIndirect, pCC->mDrawcount, pCC->mMaxdrawcount, pCC->mStride);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_PolygonOffsetClamp: {
			GlCmdPolygonOffsetClamp* pCC = (GlCmdPolygonOffsetClamp*)pCmd;
			glPolygonOffsetClamp(pCC->mFactor, pCC->mUnits, pCC->mClamp);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_PrimitiveBoundingBoxARB: {
			GlCmdPrimitiveBoundingBoxARB* pCC = (GlCmdPrimitiveBoundingBoxARB*)pCmd;
			glPrimitiveBoundingBoxARB(pCC->mMinx, pCC->mMiny, pCC->mMinz, pCC->mMinw, pCC->mMaxx, pCC->mMaxy, pCC->mMaxz, pCC->mMaxw);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetTextureHandleARB: {
			GlCmdGetTextureHandleARB* pCC = (GlCmdGetTextureHandleARB*)pCmd;
			glGetTextureHandleARB(pCC->mTexture);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetTextureSamplerHandleARB: {
			GlCmdGetTextureSamplerHandleARB* pCC = (GlCmdGetTextureSamplerHandleARB*)pCmd;
			glGetTextureSamplerHandleARB(pCC->mTexture, pCC->mSampler);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MakeTextureHandleResidentARB: {
			GlCmdMakeTextureHandleResidentARB* pCC = (GlCmdMakeTextureHandleResidentARB*)pCmd;
			glMakeTextureHandleResidentARB(pCC->mHandle);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MakeTextureHandleNonResidentARB: {
			GlCmdMakeTextureHandleNonResidentARB* pCC = (GlCmdMakeTextureHandleNonResidentARB*)pCmd;
			glMakeTextureHandleNonResidentARB(pCC->mHandle);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetImageHandleARB: {
			GlCmdGetImageHandleARB* pCC = (GlCmdGetImageHandleARB*)pCmd;
			glGetImageHandleARB(pCC->mTexture, pCC->mLevel, pCC->mLayered, pCC->mLayer, pCC->mFormat);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MakeImageHandleResidentARB: {
			GlCmdMakeImageHandleResidentARB* pCC = (GlCmdMakeImageHandleResidentARB*)pCmd;
			glMakeImageHandleResidentARB(pCC->mHandle, pCC->mAccess);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MakeImageHandleNonResidentARB: {
			GlCmdMakeImageHandleNonResidentARB* pCC = (GlCmdMakeImageHandleNonResidentARB*)pCmd;
			glMakeImageHandleNonResidentARB(pCC->mHandle);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_UniformHandleui64ARB: {
			GlCmdUniformHandleui64ARB* pCC = (GlCmdUniformHandleui64ARB*)pCmd;
			glUniformHandleui64ARB(pCC->mLocation, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_UniformHandleui64vARB: {
			GlCmdUniformHandleui64vARB* pCC = (GlCmdUniformHandleui64vARB*)pCmd;
			glUniformHandleui64vARB(pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniformHandleui64ARB: {
			GlCmdProgramUniformHandleui64ARB* pCC = (GlCmdProgramUniformHandleui64ARB*)pCmd;
			glProgramUniformHandleui64ARB(pCC->mProgram, pCC->mLocation, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniformHandleui64vARB: {
			GlCmdProgramUniformHandleui64vARB* pCC = (GlCmdProgramUniformHandleui64vARB*)pCmd;
			glProgramUniformHandleui64vARB(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValues);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_IsTextureHandleResidentARB: {
			GlCmdIsTextureHandleResidentARB* pCC = (GlCmdIsTextureHandleResidentARB*)pCmd;
			glIsTextureHandleResidentARB(pCC->mHandle);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_IsImageHandleResidentARB: {
			GlCmdIsImageHandleResidentARB* pCC = (GlCmdIsImageHandleResidentARB*)pCmd;
			glIsImageHandleResidentARB(pCC->mHandle);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribL1ui64ARB: {
			GlCmdVertexAttribL1ui64ARB* pCC = (GlCmdVertexAttribL1ui64ARB*)pCmd;
			glVertexAttribL1ui64ARB(pCC->mIndex, pCC->mX);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribL1ui64vARB: {
			GlCmdVertexAttribL1ui64vARB* pCC = (GlCmdVertexAttribL1ui64vARB*)pCmd;
			glVertexAttribL1ui64vARB(pCC->mIndex, pCC->mV);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetVertexAttribLui64vARB: {
			GlCmdGetVertexAttribLui64vARB* pCC = (GlCmdGetVertexAttribLui64vARB*)pCmd;
			glGetVertexAttribLui64vARB(pCC->mIndex, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CreateSyncFromCLeventARB: {
			GlCmdCreateSyncFromCLeventARB* pCC = (GlCmdCreateSyncFromCLeventARB*)pCmd;
			glCreateSyncFromCLeventARB(pCC->mContext, pCC->mEvent, pCC->mFlags);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DispatchComputeGroupSizeARB: {
			GlCmdDispatchComputeGroupSizeARB* pCC = (GlCmdDispatchComputeGroupSizeARB*)pCmd;
			glDispatchComputeGroupSizeARB(pCC->mNum_Groups_X, pCC->mNum_Groups_Y, pCC->mNum_Groups_Z, pCC->mGroup_Size_X, pCC->mGroup_Size_Y, pCC->mGroup_Size_Z);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DebugMessageControlARB: {
			GlCmdDebugMessageControlARB* pCC = (GlCmdDebugMessageControlARB*)pCmd;
			glDebugMessageControlARB(pCC->mSource, pCC->mType, pCC->mSeverity, pCC->mCount, pCC->mIds, pCC->mEnabled);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DebugMessageInsertARB: {
			GlCmdDebugMessageInsertARB* pCC = (GlCmdDebugMessageInsertARB*)pCmd;
			glDebugMessageInsertARB(pCC->mSource, pCC->mType, pCC->mId, pCC->mSeverity, pCC->mLength, pCC->mBuf);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DebugMessageCallbackARB: {
			GlCmdDebugMessageCallbackARB* pCC = (GlCmdDebugMessageCallbackARB*)pCmd;
			glDebugMessageCallbackARB(pCC->mCallback, pCC->mUserparam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetDebugMessageLogARB: {
			GlCmdGetDebugMessageLogARB* pCC = (GlCmdGetDebugMessageLogARB*)pCmd;
			glGetDebugMessageLogARB(pCC->mCount, pCC->mBufsize, pCC->mSources, pCC->mTypes, pCC->mIds, pCC->mSeverities, pCC->mLengths, pCC->mMessagelog);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BlendEquationiARB: {
			GlCmdBlendEquationiARB* pCC = (GlCmdBlendEquationiARB*)pCmd;
			glBlendEquationiARB(pCC->mBuf, pCC->mMode);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BlendEquationSeparateiARB: {
			GlCmdBlendEquationSeparateiARB* pCC = (GlCmdBlendEquationSeparateiARB*)pCmd;
			glBlendEquationSeparateiARB(pCC->mBuf, pCC->mModergb, pCC->mModealpha);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BlendFunciARB: {
			GlCmdBlendFunciARB* pCC = (GlCmdBlendFunciARB*)pCmd;
			glBlendFunciARB(pCC->mBuf, pCC->mSrc, pCC->mDst);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BlendFuncSeparateiARB: {
			GlCmdBlendFuncSeparateiARB* pCC = (GlCmdBlendFuncSeparateiARB*)pCmd;
			glBlendFuncSeparateiARB(pCC->mBuf, pCC->mSrcrgb, pCC->mDstrgb, pCC->mSrcalpha, pCC->mDstalpha);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DrawArraysInstancedARB: {
			GlCmdDrawArraysInstancedARB* pCC = (GlCmdDrawArraysInstancedARB*)pCmd;
			glDrawArraysInstancedARB(pCC->mMode, pCC->mFirst, pCC->mCount, pCC->mPrimcount);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DrawElementsInstancedARB: {
			GlCmdDrawElementsInstancedARB* pCC = (GlCmdDrawElementsInstancedARB*)pCmd;
			glDrawElementsInstancedARB(pCC->mMode, pCC->mCount, pCC->mType, pCC->mIndices, pCC->mPrimcount);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramParameteriARB: {
			GlCmdProgramParameteriARB* pCC = (GlCmdProgramParameteriARB*)pCmd;
			glProgramParameteriARB(pCC->mProgram, pCC->mPname, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_FramebufferTextureARB: {
			GlCmdFramebufferTextureARB* pCC = (GlCmdFramebufferTextureARB*)pCmd;
			glFramebufferTextureARB(pCC->mTarget, pCC->mAttachment, pCC->mTexture, pCC->mLevel);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_FramebufferTextureLayerARB: {
			GlCmdFramebufferTextureLayerARB* pCC = (GlCmdFramebufferTextureLayerARB*)pCmd;
			glFramebufferTextureLayerARB(pCC->mTarget, pCC->mAttachment, pCC->mTexture, pCC->mLevel, pCC->mLayer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_FramebufferTextureFaceARB: {
			GlCmdFramebufferTextureFaceARB* pCC = (GlCmdFramebufferTextureFaceARB*)pCmd;
			glFramebufferTextureFaceARB(pCC->mTarget, pCC->mAttachment, pCC->mTexture, pCC->mLevel, pCC->mFace);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_SpecializeShaderARB: {
			GlCmdSpecializeShaderARB* pCC = (GlCmdSpecializeShaderARB*)pCmd;
			glSpecializeShaderARB(pCC->mShader, pCC->mPentrypoint, pCC->mNumspecializationconstants, pCC->mPconstantindex, pCC->mPconstantvalue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform1i64ARB: {
			GlCmdUniform1i64ARB* pCC = (GlCmdUniform1i64ARB*)pCmd;
			glUniform1i64ARB(pCC->mLocation, pCC->mX);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform2i64ARB: {
			GlCmdUniform2i64ARB* pCC = (GlCmdUniform2i64ARB*)pCmd;
			glUniform2i64ARB(pCC->mLocation, pCC->mX, pCC->mY);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform3i64ARB: {
			GlCmdUniform3i64ARB* pCC = (GlCmdUniform3i64ARB*)pCmd;
			glUniform3i64ARB(pCC->mLocation, pCC->mX, pCC->mY, pCC->mZ);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform4i64ARB: {
			GlCmdUniform4i64ARB* pCC = (GlCmdUniform4i64ARB*)pCmd;
			glUniform4i64ARB(pCC->mLocation, pCC->mX, pCC->mY, pCC->mZ, pCC->mW);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform1i64vARB: {
			GlCmdUniform1i64vARB* pCC = (GlCmdUniform1i64vARB*)pCmd;
			glUniform1i64vARB(pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform2i64vARB: {
			GlCmdUniform2i64vARB* pCC = (GlCmdUniform2i64vARB*)pCmd;
			glUniform2i64vARB(pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform3i64vARB: {
			GlCmdUniform3i64vARB* pCC = (GlCmdUniform3i64vARB*)pCmd;
			glUniform3i64vARB(pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform4i64vARB: {
			GlCmdUniform4i64vARB* pCC = (GlCmdUniform4i64vARB*)pCmd;
			glUniform4i64vARB(pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform1ui64ARB: {
			GlCmdUniform1ui64ARB* pCC = (GlCmdUniform1ui64ARB*)pCmd;
			glUniform1ui64ARB(pCC->mLocation, pCC->mX);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform2ui64ARB: {
			GlCmdUniform2ui64ARB* pCC = (GlCmdUniform2ui64ARB*)pCmd;
			glUniform2ui64ARB(pCC->mLocation, pCC->mX, pCC->mY);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform3ui64ARB: {
			GlCmdUniform3ui64ARB* pCC = (GlCmdUniform3ui64ARB*)pCmd;
			glUniform3ui64ARB(pCC->mLocation, pCC->mX, pCC->mY, pCC->mZ);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform4ui64ARB: {
			GlCmdUniform4ui64ARB* pCC = (GlCmdUniform4ui64ARB*)pCmd;
			glUniform4ui64ARB(pCC->mLocation, pCC->mX, pCC->mY, pCC->mZ, pCC->mW);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform1ui64vARB: {
			GlCmdUniform1ui64vARB* pCC = (GlCmdUniform1ui64vARB*)pCmd;
			glUniform1ui64vARB(pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform2ui64vARB: {
			GlCmdUniform2ui64vARB* pCC = (GlCmdUniform2ui64vARB*)pCmd;
			glUniform2ui64vARB(pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform3ui64vARB: {
			GlCmdUniform3ui64vARB* pCC = (GlCmdUniform3ui64vARB*)pCmd;
			glUniform3ui64vARB(pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_Uniform4ui64vARB: {
			GlCmdUniform4ui64vARB* pCC = (GlCmdUniform4ui64vARB*)pCmd;
			glUniform4ui64vARB(pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetUniformi64vARB: {
			GlCmdGetUniformi64vARB* pCC = (GlCmdGetUniformi64vARB*)pCmd;
			glGetUniformi64vARB(pCC->mProgram, pCC->mLocation, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetUniformui64vARB: {
			GlCmdGetUniformui64vARB* pCC = (GlCmdGetUniformui64vARB*)pCmd;
			glGetUniformui64vARB(pCC->mProgram, pCC->mLocation, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetnUniformi64vARB: {
			GlCmdGetnUniformi64vARB* pCC = (GlCmdGetnUniformi64vARB*)pCmd;
			glGetnUniformi64vARB(pCC->mProgram, pCC->mLocation, pCC->mBufsize, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetnUniformui64vARB: {
			GlCmdGetnUniformui64vARB* pCC = (GlCmdGetnUniformui64vARB*)pCmd;
			glGetnUniformui64vARB(pCC->mProgram, pCC->mLocation, pCC->mBufsize, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform1i64ARB: {
			GlCmdProgramUniform1i64ARB* pCC = (GlCmdProgramUniform1i64ARB*)pCmd;
			glProgramUniform1i64ARB(pCC->mProgram, pCC->mLocation, pCC->mX);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform2i64ARB: {
			GlCmdProgramUniform2i64ARB* pCC = (GlCmdProgramUniform2i64ARB*)pCmd;
			glProgramUniform2i64ARB(pCC->mProgram, pCC->mLocation, pCC->mX, pCC->mY);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform3i64ARB: {
			GlCmdProgramUniform3i64ARB* pCC = (GlCmdProgramUniform3i64ARB*)pCmd;
			glProgramUniform3i64ARB(pCC->mProgram, pCC->mLocation, pCC->mX, pCC->mY, pCC->mZ);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform4i64ARB: {
			GlCmdProgramUniform4i64ARB* pCC = (GlCmdProgramUniform4i64ARB*)pCmd;
			glProgramUniform4i64ARB(pCC->mProgram, pCC->mLocation, pCC->mX, pCC->mY, pCC->mZ, pCC->mW);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform1i64vARB: {
			GlCmdProgramUniform1i64vARB* pCC = (GlCmdProgramUniform1i64vARB*)pCmd;
			glProgramUniform1i64vARB(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform2i64vARB: {
			GlCmdProgramUniform2i64vARB* pCC = (GlCmdProgramUniform2i64vARB*)pCmd;
			glProgramUniform2i64vARB(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform3i64vARB: {
			GlCmdProgramUniform3i64vARB* pCC = (GlCmdProgramUniform3i64vARB*)pCmd;
			glProgramUniform3i64vARB(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform4i64vARB: {
			GlCmdProgramUniform4i64vARB* pCC = (GlCmdProgramUniform4i64vARB*)pCmd;
			glProgramUniform4i64vARB(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform1ui64ARB: {
			GlCmdProgramUniform1ui64ARB* pCC = (GlCmdProgramUniform1ui64ARB*)pCmd;
			glProgramUniform1ui64ARB(pCC->mProgram, pCC->mLocation, pCC->mX);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform2ui64ARB: {
			GlCmdProgramUniform2ui64ARB* pCC = (GlCmdProgramUniform2ui64ARB*)pCmd;
			glProgramUniform2ui64ARB(pCC->mProgram, pCC->mLocation, pCC->mX, pCC->mY);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform3ui64ARB: {
			GlCmdProgramUniform3ui64ARB* pCC = (GlCmdProgramUniform3ui64ARB*)pCmd;
			glProgramUniform3ui64ARB(pCC->mProgram, pCC->mLocation, pCC->mX, pCC->mY, pCC->mZ);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform4ui64ARB: {
			GlCmdProgramUniform4ui64ARB* pCC = (GlCmdProgramUniform4ui64ARB*)pCmd;
			glProgramUniform4ui64ARB(pCC->mProgram, pCC->mLocation, pCC->mX, pCC->mY, pCC->mZ, pCC->mW);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform1ui64vARB: {
			GlCmdProgramUniform1ui64vARB* pCC = (GlCmdProgramUniform1ui64vARB*)pCmd;
			glProgramUniform1ui64vARB(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform2ui64vARB: {
			GlCmdProgramUniform2ui64vARB* pCC = (GlCmdProgramUniform2ui64vARB*)pCmd;
			glProgramUniform2ui64vARB(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform3ui64vARB: {
			GlCmdProgramUniform3ui64vARB* pCC = (GlCmdProgramUniform3ui64vARB*)pCmd;
			glProgramUniform3ui64vARB(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform4ui64vARB: {
			GlCmdProgramUniform4ui64vARB* pCC = (GlCmdProgramUniform4ui64vARB*)pCmd;
			glProgramUniform4ui64vARB(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiDrawArraysIndirectCountARB: {
			GlCmdMultiDrawArraysIndirectCountARB* pCC = (GlCmdMultiDrawArraysIndirectCountARB*)pCmd;
			glMultiDrawArraysIndirectCountARB(pCC->mMode, pCC->mIndirect, pCC->mDrawcount, pCC->mMaxdrawcount, pCC->mStride);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiDrawElementsIndirectCountARB: {
			GlCmdMultiDrawElementsIndirectCountARB* pCC = (GlCmdMultiDrawElementsIndirectCountARB*)pCmd;
			glMultiDrawElementsIndirectCountARB(pCC->mMode, pCC->mType, pCC->mIndirect, pCC->mDrawcount, pCC->mMaxdrawcount, pCC->mStride);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexAttribDivisorARB: {
			GlCmdVertexAttribDivisorARB* pCC = (GlCmdVertexAttribDivisorARB*)pCmd;
			glVertexAttribDivisorARB(pCC->mIndex, pCC->mDivisor);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MaxShaderCompilerThreadsARB: {
			GlCmdMaxShaderCompilerThreadsARB* pCC = (GlCmdMaxShaderCompilerThreadsARB*)pCmd;
			glMaxShaderCompilerThreadsARB(pCC->mCount);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetGraphicsResetStatusARB: {
			GlCmdGetGraphicsResetStatusARB* pCC = (GlCmdGetGraphicsResetStatusARB*)pCmd;
			glGetGraphicsResetStatusARB();
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetnTexImageARB: {
			GlCmdGetnTexImageARB* pCC = (GlCmdGetnTexImageARB*)pCmd;
			glGetnTexImageARB(pCC->mTarget, pCC->mLevel, pCC->mFormat, pCC->mType, pCC->mBufsize, pCC->mImg);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ReadnPixelsARB: {
			GlCmdReadnPixelsARB* pCC = (GlCmdReadnPixelsARB*)pCmd;
			glReadnPixelsARB(pCC->mX, pCC->mY, pCC->mWidth, pCC->mHeight, pCC->mFormat, pCC->mType, pCC->mBufsize, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetnCompressedTexImageARB: {
			GlCmdGetnCompressedTexImageARB* pCC = (GlCmdGetnCompressedTexImageARB*)pCmd;
			glGetnCompressedTexImageARB(pCC->mTarget, pCC->mLod, pCC->mBufsize, pCC->mImg);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetnUniformfvARB: {
			GlCmdGetnUniformfvARB* pCC = (GlCmdGetnUniformfvARB*)pCmd;
			glGetnUniformfvARB(pCC->mProgram, pCC->mLocation, pCC->mBufsize, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetnUniformivARB: {
			GlCmdGetnUniformivARB* pCC = (GlCmdGetnUniformivARB*)pCmd;
			glGetnUniformivARB(pCC->mProgram, pCC->mLocation, pCC->mBufsize, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetnUniformuivARB: {
			GlCmdGetnUniformuivARB* pCC = (GlCmdGetnUniformuivARB*)pCmd;
			glGetnUniformuivARB(pCC->mProgram, pCC->mLocation, pCC->mBufsize, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetnUniformdvARB: {
			GlCmdGetnUniformdvARB* pCC = (GlCmdGetnUniformdvARB*)pCmd;
			glGetnUniformdvARB(pCC->mProgram, pCC->mLocation, pCC->mBufsize, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MinSampleShadingARB: {
			GlCmdMinSampleShadingARB* pCC = (GlCmdMinSampleShadingARB*)pCmd;
			glMinSampleShadingARB(pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedStringARB: {
			GlCmdNamedStringARB* pCC = (GlCmdNamedStringARB*)pCmd;
			glNamedStringARB(pCC->mType, pCC->mNamelen, pCC->mName, pCC->mStringlen, pCC->mString);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DeleteNamedStringARB: {
			GlCmdDeleteNamedStringARB* pCC = (GlCmdDeleteNamedStringARB*)pCmd;
			glDeleteNamedStringARB(pCC->mNamelen, pCC->mName);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CompileShaderIncludeARB: {
			GlCmdCompileShaderIncludeARB* pCC = (GlCmdCompileShaderIncludeARB*)pCmd;
			glCompileShaderIncludeARB(pCC->mShader, pCC->mCount, pCC->mPath, pCC->mLength);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_IsNamedStringARB: {
			GlCmdIsNamedStringARB* pCC = (GlCmdIsNamedStringARB*)pCmd;
			glIsNamedStringARB(pCC->mNamelen, pCC->mName);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetNamedStringARB: {
			GlCmdGetNamedStringARB* pCC = (GlCmdGetNamedStringARB*)pCmd;
			glGetNamedStringARB(pCC->mNamelen, pCC->mName, pCC->mBufsize, pCC->mStringlen, pCC->mString);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetNamedStringivARB: {
			GlCmdGetNamedStringivARB* pCC = (GlCmdGetNamedStringivARB*)pCmd;
			glGetNamedStringivARB(pCC->mNamelen, pCC->mName, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TexPageCommitmentARB: {
			GlCmdTexPageCommitmentARB* pCC = (GlCmdTexPageCommitmentARB*)pCmd;
			glTexPageCommitmentARB(pCC->mTarget, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mZoffset, pCC->mWidth, pCC->mHeight, pCC->mDepth, pCC->mCommit);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TexBufferARB: {
			GlCmdTexBufferARB* pCC = (GlCmdTexBufferARB*)pCmd;
			glTexBufferARB(pCC->mTarget, pCC->mInternalformat, pCC->mBuffer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BlendBarrierKHR: {
			GlCmdBlendBarrierKHR* pCC = (GlCmdBlendBarrierKHR*)pCmd;
			glBlendBarrierKHR();
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MaxShaderCompilerThreadsKHR: {
			GlCmdMaxShaderCompilerThreadsKHR* pCC = (GlCmdMaxShaderCompilerThreadsKHR*)pCmd;
			glMaxShaderCompilerThreadsKHR(pCC->mCount);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_LabelObjectEXT: {
			GlCmdLabelObjectEXT* pCC = (GlCmdLabelObjectEXT*)pCmd;
			glLabelObjectEXT(pCC->mType, pCC->mObject, pCC->mLength, pCC->mLabel);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetObjectLabelEXT: {
			GlCmdGetObjectLabelEXT* pCC = (GlCmdGetObjectLabelEXT*)pCmd;
			glGetObjectLabelEXT(pCC->mType, pCC->mObject, pCC->mBufsize, pCC->mLength, pCC->mLabel);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_InsertEventMarkerEXT: {
			GlCmdInsertEventMarkerEXT* pCC = (GlCmdInsertEventMarkerEXT*)pCmd;
			glInsertEventMarkerEXT(pCC->mLength, pCC->mMarker);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_PushGroupMarkerEXT: {
			GlCmdPushGroupMarkerEXT* pCC = (GlCmdPushGroupMarkerEXT*)pCmd;
			glPushGroupMarkerEXT(pCC->mLength, pCC->mMarker);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_PopGroupMarkerEXT: {
			GlCmdPopGroupMarkerEXT* pCC = (GlCmdPopGroupMarkerEXT*)pCmd;
			glPopGroupMarkerEXT();
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MatrixLoadfEXT: {
			GlCmdMatrixLoadfEXT* pCC = (GlCmdMatrixLoadfEXT*)pCmd;
			glMatrixLoadfEXT(pCC->mMode, pCC->mM);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MatrixLoaddEXT: {
			GlCmdMatrixLoaddEXT* pCC = (GlCmdMatrixLoaddEXT*)pCmd;
			glMatrixLoaddEXT(pCC->mMode, pCC->mM);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MatrixMultfEXT: {
			GlCmdMatrixMultfEXT* pCC = (GlCmdMatrixMultfEXT*)pCmd;
			glMatrixMultfEXT(pCC->mMode, pCC->mM);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MatrixMultdEXT: {
			GlCmdMatrixMultdEXT* pCC = (GlCmdMatrixMultdEXT*)pCmd;
			glMatrixMultdEXT(pCC->mMode, pCC->mM);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MatrixLoadIdentityEXT: {
			GlCmdMatrixLoadIdentityEXT* pCC = (GlCmdMatrixLoadIdentityEXT*)pCmd;
			glMatrixLoadIdentityEXT(pCC->mMode);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MatrixRotatefEXT: {
			GlCmdMatrixRotatefEXT* pCC = (GlCmdMatrixRotatefEXT*)pCmd;
			glMatrixRotatefEXT(pCC->mMode, pCC->mAngle, pCC->mX, pCC->mY, pCC->mZ);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MatrixRotatedEXT: {
			GlCmdMatrixRotatedEXT* pCC = (GlCmdMatrixRotatedEXT*)pCmd;
			glMatrixRotatedEXT(pCC->mMode, pCC->mAngle, pCC->mX, pCC->mY, pCC->mZ);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MatrixScalefEXT: {
			GlCmdMatrixScalefEXT* pCC = (GlCmdMatrixScalefEXT*)pCmd;
			glMatrixScalefEXT(pCC->mMode, pCC->mX, pCC->mY, pCC->mZ);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MatrixScaledEXT: {
			GlCmdMatrixScaledEXT* pCC = (GlCmdMatrixScaledEXT*)pCmd;
			glMatrixScaledEXT(pCC->mMode, pCC->mX, pCC->mY, pCC->mZ);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MatrixTranslatefEXT: {
			GlCmdMatrixTranslatefEXT* pCC = (GlCmdMatrixTranslatefEXT*)pCmd;
			glMatrixTranslatefEXT(pCC->mMode, pCC->mX, pCC->mY, pCC->mZ);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MatrixTranslatedEXT: {
			GlCmdMatrixTranslatedEXT* pCC = (GlCmdMatrixTranslatedEXT*)pCmd;
			glMatrixTranslatedEXT(pCC->mMode, pCC->mX, pCC->mY, pCC->mZ);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MatrixFrustumEXT: {
			GlCmdMatrixFrustumEXT* pCC = (GlCmdMatrixFrustumEXT*)pCmd;
			glMatrixFrustumEXT(pCC->mMode, pCC->mLeft, pCC->mRight, pCC->mBottom, pCC->mTop, pCC->mZnear, pCC->mZfar);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MatrixOrthoEXT: {
			GlCmdMatrixOrthoEXT* pCC = (GlCmdMatrixOrthoEXT*)pCmd;
			glMatrixOrthoEXT(pCC->mMode, pCC->mLeft, pCC->mRight, pCC->mBottom, pCC->mTop, pCC->mZnear, pCC->mZfar);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MatrixPopEXT: {
			GlCmdMatrixPopEXT* pCC = (GlCmdMatrixPopEXT*)pCmd;
			glMatrixPopEXT(pCC->mMode);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MatrixPushEXT: {
			GlCmdMatrixPushEXT* pCC = (GlCmdMatrixPushEXT*)pCmd;
			glMatrixPushEXT(pCC->mMode);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ClientAttribDefaultEXT: {
			GlCmdClientAttribDefaultEXT* pCC = (GlCmdClientAttribDefaultEXT*)pCmd;
			glClientAttribDefaultEXT(pCC->mMask);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_PushClientAttribDefaultEXT: {
			GlCmdPushClientAttribDefaultEXT* pCC = (GlCmdPushClientAttribDefaultEXT*)pCmd;
			glPushClientAttribDefaultEXT(pCC->mMask);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureParameterfEXT: {
			GlCmdTextureParameterfEXT* pCC = (GlCmdTextureParameterfEXT*)pCmd;
			glTextureParameterfEXT(pCC->mTexture, pCC->mTarget, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureParameterfvEXT: {
			GlCmdTextureParameterfvEXT* pCC = (GlCmdTextureParameterfvEXT*)pCmd;
			glTextureParameterfvEXT(pCC->mTexture, pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureParameteriEXT: {
			GlCmdTextureParameteriEXT* pCC = (GlCmdTextureParameteriEXT*)pCmd;
			glTextureParameteriEXT(pCC->mTexture, pCC->mTarget, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureParameterivEXT: {
			GlCmdTextureParameterivEXT* pCC = (GlCmdTextureParameterivEXT*)pCmd;
			glTextureParameterivEXT(pCC->mTexture, pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureImage1DEXT: {
			GlCmdTextureImage1DEXT* pCC = (GlCmdTextureImage1DEXT*)pCmd;
			glTextureImage1DEXT(pCC->mTexture, pCC->mTarget, pCC->mLevel, pCC->mInternalformat, pCC->mWidth, pCC->mBorder, pCC->mFormat, pCC->mType, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureImage2DEXT: {
			GlCmdTextureImage2DEXT* pCC = (GlCmdTextureImage2DEXT*)pCmd;
			glTextureImage2DEXT(pCC->mTexture, pCC->mTarget, pCC->mLevel, pCC->mInternalformat, pCC->mWidth, pCC->mHeight, pCC->mBorder, pCC->mFormat, pCC->mType, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureSubImage1DEXT: {
			GlCmdTextureSubImage1DEXT* pCC = (GlCmdTextureSubImage1DEXT*)pCmd;
			glTextureSubImage1DEXT(pCC->mTexture, pCC->mTarget, pCC->mLevel, pCC->mXoffset, pCC->mWidth, pCC->mFormat, pCC->mType, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureSubImage2DEXT: {
			GlCmdTextureSubImage2DEXT* pCC = (GlCmdTextureSubImage2DEXT*)pCmd;
			glTextureSubImage2DEXT(pCC->mTexture, pCC->mTarget, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mWidth, pCC->mHeight, pCC->mFormat, pCC->mType, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CopyTextureImage1DEXT: {
			GlCmdCopyTextureImage1DEXT* pCC = (GlCmdCopyTextureImage1DEXT*)pCmd;
			glCopyTextureImage1DEXT(pCC->mTexture, pCC->mTarget, pCC->mLevel, pCC->mInternalformat, pCC->mX, pCC->mY, pCC->mWidth, pCC->mBorder);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CopyTextureImage2DEXT: {
			GlCmdCopyTextureImage2DEXT* pCC = (GlCmdCopyTextureImage2DEXT*)pCmd;
			glCopyTextureImage2DEXT(pCC->mTexture, pCC->mTarget, pCC->mLevel, pCC->mInternalformat, pCC->mX, pCC->mY, pCC->mWidth, pCC->mHeight, pCC->mBorder);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CopyTextureSubImage1DEXT: {
			GlCmdCopyTextureSubImage1DEXT* pCC = (GlCmdCopyTextureSubImage1DEXT*)pCmd;
			glCopyTextureSubImage1DEXT(pCC->mTexture, pCC->mTarget, pCC->mLevel, pCC->mXoffset, pCC->mX, pCC->mY, pCC->mWidth);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CopyTextureSubImage2DEXT: {
			GlCmdCopyTextureSubImage2DEXT* pCC = (GlCmdCopyTextureSubImage2DEXT*)pCmd;
			glCopyTextureSubImage2DEXT(pCC->mTexture, pCC->mTarget, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mX, pCC->mY, pCC->mWidth, pCC->mHeight);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetTextureImageEXT: {
			GlCmdGetTextureImageEXT* pCC = (GlCmdGetTextureImageEXT*)pCmd;
			glGetTextureImageEXT(pCC->mTexture, pCC->mTarget, pCC->mLevel, pCC->mFormat, pCC->mType, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetTextureParameterfvEXT: {
			GlCmdGetTextureParameterfvEXT* pCC = (GlCmdGetTextureParameterfvEXT*)pCmd;
			glGetTextureParameterfvEXT(pCC->mTexture, pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetTextureParameterivEXT: {
			GlCmdGetTextureParameterivEXT* pCC = (GlCmdGetTextureParameterivEXT*)pCmd;
			glGetTextureParameterivEXT(pCC->mTexture, pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetTextureLevelParameterfvEXT: {
			GlCmdGetTextureLevelParameterfvEXT* pCC = (GlCmdGetTextureLevelParameterfvEXT*)pCmd;
			glGetTextureLevelParameterfvEXT(pCC->mTexture, pCC->mTarget, pCC->mLevel, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetTextureLevelParameterivEXT: {
			GlCmdGetTextureLevelParameterivEXT* pCC = (GlCmdGetTextureLevelParameterivEXT*)pCmd;
			glGetTextureLevelParameterivEXT(pCC->mTexture, pCC->mTarget, pCC->mLevel, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureImage3DEXT: {
			GlCmdTextureImage3DEXT* pCC = (GlCmdTextureImage3DEXT*)pCmd;
			glTextureImage3DEXT(pCC->mTexture, pCC->mTarget, pCC->mLevel, pCC->mInternalformat, pCC->mWidth, pCC->mHeight, pCC->mDepth, pCC->mBorder, pCC->mFormat, pCC->mType, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureSubImage3DEXT: {
			GlCmdTextureSubImage3DEXT* pCC = (GlCmdTextureSubImage3DEXT*)pCmd;
			glTextureSubImage3DEXT(pCC->mTexture, pCC->mTarget, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mZoffset, pCC->mWidth, pCC->mHeight, pCC->mDepth, pCC->mFormat, pCC->mType, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CopyTextureSubImage3DEXT: {
			GlCmdCopyTextureSubImage3DEXT* pCC = (GlCmdCopyTextureSubImage3DEXT*)pCmd;
			glCopyTextureSubImage3DEXT(pCC->mTexture, pCC->mTarget, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mZoffset, pCC->mX, pCC->mY, pCC->mWidth, pCC->mHeight);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_BindMultiTextureEXT: {
			GlCmdBindMultiTextureEXT* pCC = (GlCmdBindMultiTextureEXT*)pCmd;
			glBindMultiTextureEXT(pCC->mTexunit, pCC->mTarget, pCC->mTexture);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiTexCoordPointerEXT: {
			GlCmdMultiTexCoordPointerEXT* pCC = (GlCmdMultiTexCoordPointerEXT*)pCmd;
			glMultiTexCoordPointerEXT(pCC->mTexunit, pCC->mSize, pCC->mType, pCC->mStride, pCC->mPointer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiTexEnvfEXT: {
			GlCmdMultiTexEnvfEXT* pCC = (GlCmdMultiTexEnvfEXT*)pCmd;
			glMultiTexEnvfEXT(pCC->mTexunit, pCC->mTarget, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiTexEnvfvEXT: {
			GlCmdMultiTexEnvfvEXT* pCC = (GlCmdMultiTexEnvfvEXT*)pCmd;
			glMultiTexEnvfvEXT(pCC->mTexunit, pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiTexEnviEXT: {
			GlCmdMultiTexEnviEXT* pCC = (GlCmdMultiTexEnviEXT*)pCmd;
			glMultiTexEnviEXT(pCC->mTexunit, pCC->mTarget, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiTexEnvivEXT: {
			GlCmdMultiTexEnvivEXT* pCC = (GlCmdMultiTexEnvivEXT*)pCmd;
			glMultiTexEnvivEXT(pCC->mTexunit, pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiTexGendEXT: {
			GlCmdMultiTexGendEXT* pCC = (GlCmdMultiTexGendEXT*)pCmd;
			glMultiTexGendEXT(pCC->mTexunit, pCC->mCoord, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiTexGendvEXT: {
			GlCmdMultiTexGendvEXT* pCC = (GlCmdMultiTexGendvEXT*)pCmd;
			glMultiTexGendvEXT(pCC->mTexunit, pCC->mCoord, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiTexGenfEXT: {
			GlCmdMultiTexGenfEXT* pCC = (GlCmdMultiTexGenfEXT*)pCmd;
			glMultiTexGenfEXT(pCC->mTexunit, pCC->mCoord, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiTexGenfvEXT: {
			GlCmdMultiTexGenfvEXT* pCC = (GlCmdMultiTexGenfvEXT*)pCmd;
			glMultiTexGenfvEXT(pCC->mTexunit, pCC->mCoord, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiTexGeniEXT: {
			GlCmdMultiTexGeniEXT* pCC = (GlCmdMultiTexGeniEXT*)pCmd;
			glMultiTexGeniEXT(pCC->mTexunit, pCC->mCoord, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiTexGenivEXT: {
			GlCmdMultiTexGenivEXT* pCC = (GlCmdMultiTexGenivEXT*)pCmd;
			glMultiTexGenivEXT(pCC->mTexunit, pCC->mCoord, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetMultiTexEnvfvEXT: {
			GlCmdGetMultiTexEnvfvEXT* pCC = (GlCmdGetMultiTexEnvfvEXT*)pCmd;
			glGetMultiTexEnvfvEXT(pCC->mTexunit, pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetMultiTexEnvivEXT: {
			GlCmdGetMultiTexEnvivEXT* pCC = (GlCmdGetMultiTexEnvivEXT*)pCmd;
			glGetMultiTexEnvivEXT(pCC->mTexunit, pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetMultiTexGendvEXT: {
			GlCmdGetMultiTexGendvEXT* pCC = (GlCmdGetMultiTexGendvEXT*)pCmd;
			glGetMultiTexGendvEXT(pCC->mTexunit, pCC->mCoord, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetMultiTexGenfvEXT: {
			GlCmdGetMultiTexGenfvEXT* pCC = (GlCmdGetMultiTexGenfvEXT*)pCmd;
			glGetMultiTexGenfvEXT(pCC->mTexunit, pCC->mCoord, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetMultiTexGenivEXT: {
			GlCmdGetMultiTexGenivEXT* pCC = (GlCmdGetMultiTexGenivEXT*)pCmd;
			glGetMultiTexGenivEXT(pCC->mTexunit, pCC->mCoord, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiTexParameteriEXT: {
			GlCmdMultiTexParameteriEXT* pCC = (GlCmdMultiTexParameteriEXT*)pCmd;
			glMultiTexParameteriEXT(pCC->mTexunit, pCC->mTarget, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiTexParameterivEXT: {
			GlCmdMultiTexParameterivEXT* pCC = (GlCmdMultiTexParameterivEXT*)pCmd;
			glMultiTexParameterivEXT(pCC->mTexunit, pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiTexParameterfEXT: {
			GlCmdMultiTexParameterfEXT* pCC = (GlCmdMultiTexParameterfEXT*)pCmd;
			glMultiTexParameterfEXT(pCC->mTexunit, pCC->mTarget, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiTexParameterfvEXT: {
			GlCmdMultiTexParameterfvEXT* pCC = (GlCmdMultiTexParameterfvEXT*)pCmd;
			glMultiTexParameterfvEXT(pCC->mTexunit, pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiTexImage1DEXT: {
			GlCmdMultiTexImage1DEXT* pCC = (GlCmdMultiTexImage1DEXT*)pCmd;
			glMultiTexImage1DEXT(pCC->mTexunit, pCC->mTarget, pCC->mLevel, pCC->mInternalformat, pCC->mWidth, pCC->mBorder, pCC->mFormat, pCC->mType, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiTexImage2DEXT: {
			GlCmdMultiTexImage2DEXT* pCC = (GlCmdMultiTexImage2DEXT*)pCmd;
			glMultiTexImage2DEXT(pCC->mTexunit, pCC->mTarget, pCC->mLevel, pCC->mInternalformat, pCC->mWidth, pCC->mHeight, pCC->mBorder, pCC->mFormat, pCC->mType, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiTexSubImage1DEXT: {
			GlCmdMultiTexSubImage1DEXT* pCC = (GlCmdMultiTexSubImage1DEXT*)pCmd;
			glMultiTexSubImage1DEXT(pCC->mTexunit, pCC->mTarget, pCC->mLevel, pCC->mXoffset, pCC->mWidth, pCC->mFormat, pCC->mType, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiTexSubImage2DEXT: {
			GlCmdMultiTexSubImage2DEXT* pCC = (GlCmdMultiTexSubImage2DEXT*)pCmd;
			glMultiTexSubImage2DEXT(pCC->mTexunit, pCC->mTarget, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mWidth, pCC->mHeight, pCC->mFormat, pCC->mType, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CopyMultiTexImage1DEXT: {
			GlCmdCopyMultiTexImage1DEXT* pCC = (GlCmdCopyMultiTexImage1DEXT*)pCmd;
			glCopyMultiTexImage1DEXT(pCC->mTexunit, pCC->mTarget, pCC->mLevel, pCC->mInternalformat, pCC->mX, pCC->mY, pCC->mWidth, pCC->mBorder);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CopyMultiTexImage2DEXT: {
			GlCmdCopyMultiTexImage2DEXT* pCC = (GlCmdCopyMultiTexImage2DEXT*)pCmd;
			glCopyMultiTexImage2DEXT(pCC->mTexunit, pCC->mTarget, pCC->mLevel, pCC->mInternalformat, pCC->mX, pCC->mY, pCC->mWidth, pCC->mHeight, pCC->mBorder);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CopyMultiTexSubImage1DEXT: {
			GlCmdCopyMultiTexSubImage1DEXT* pCC = (GlCmdCopyMultiTexSubImage1DEXT*)pCmd;
			glCopyMultiTexSubImage1DEXT(pCC->mTexunit, pCC->mTarget, pCC->mLevel, pCC->mXoffset, pCC->mX, pCC->mY, pCC->mWidth);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CopyMultiTexSubImage2DEXT: {
			GlCmdCopyMultiTexSubImage2DEXT* pCC = (GlCmdCopyMultiTexSubImage2DEXT*)pCmd;
			glCopyMultiTexSubImage2DEXT(pCC->mTexunit, pCC->mTarget, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mX, pCC->mY, pCC->mWidth, pCC->mHeight);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetMultiTexImageEXT: {
			GlCmdGetMultiTexImageEXT* pCC = (GlCmdGetMultiTexImageEXT*)pCmd;
			glGetMultiTexImageEXT(pCC->mTexunit, pCC->mTarget, pCC->mLevel, pCC->mFormat, pCC->mType, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetMultiTexParameterfvEXT: {
			GlCmdGetMultiTexParameterfvEXT* pCC = (GlCmdGetMultiTexParameterfvEXT*)pCmd;
			glGetMultiTexParameterfvEXT(pCC->mTexunit, pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetMultiTexParameterivEXT: {
			GlCmdGetMultiTexParameterivEXT* pCC = (GlCmdGetMultiTexParameterivEXT*)pCmd;
			glGetMultiTexParameterivEXT(pCC->mTexunit, pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetMultiTexLevelParameterfvEXT: {
			GlCmdGetMultiTexLevelParameterfvEXT* pCC = (GlCmdGetMultiTexLevelParameterfvEXT*)pCmd;
			glGetMultiTexLevelParameterfvEXT(pCC->mTexunit, pCC->mTarget, pCC->mLevel, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetMultiTexLevelParameterivEXT: {
			GlCmdGetMultiTexLevelParameterivEXT* pCC = (GlCmdGetMultiTexLevelParameterivEXT*)pCmd;
			glGetMultiTexLevelParameterivEXT(pCC->mTexunit, pCC->mTarget, pCC->mLevel, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiTexImage3DEXT: {
			GlCmdMultiTexImage3DEXT* pCC = (GlCmdMultiTexImage3DEXT*)pCmd;
			glMultiTexImage3DEXT(pCC->mTexunit, pCC->mTarget, pCC->mLevel, pCC->mInternalformat, pCC->mWidth, pCC->mHeight, pCC->mDepth, pCC->mBorder, pCC->mFormat, pCC->mType, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiTexSubImage3DEXT: {
			GlCmdMultiTexSubImage3DEXT* pCC = (GlCmdMultiTexSubImage3DEXT*)pCmd;
			glMultiTexSubImage3DEXT(pCC->mTexunit, pCC->mTarget, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mZoffset, pCC->mWidth, pCC->mHeight, pCC->mDepth, pCC->mFormat, pCC->mType, pCC->mPixels);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CopyMultiTexSubImage3DEXT: {
			GlCmdCopyMultiTexSubImage3DEXT* pCC = (GlCmdCopyMultiTexSubImage3DEXT*)pCmd;
			glCopyMultiTexSubImage3DEXT(pCC->mTexunit, pCC->mTarget, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mZoffset, pCC->mX, pCC->mY, pCC->mWidth, pCC->mHeight);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_EnableClientStateIndexedEXT: {
			GlCmdEnableClientStateIndexedEXT* pCC = (GlCmdEnableClientStateIndexedEXT*)pCmd;
			glEnableClientStateIndexedEXT(pCC->mArray, pCC->mIndex);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DisableClientStateIndexedEXT: {
			GlCmdDisableClientStateIndexedEXT* pCC = (GlCmdDisableClientStateIndexedEXT*)pCmd;
			glDisableClientStateIndexedEXT(pCC->mArray, pCC->mIndex);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetFloatIndexedvEXT: {
			GlCmdGetFloatIndexedvEXT* pCC = (GlCmdGetFloatIndexedvEXT*)pCmd;
			glGetFloatIndexedvEXT(pCC->mTarget, pCC->mIndex, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetDoubleIndexedvEXT: {
			GlCmdGetDoubleIndexedvEXT* pCC = (GlCmdGetDoubleIndexedvEXT*)pCmd;
			glGetDoubleIndexedvEXT(pCC->mTarget, pCC->mIndex, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetPointerIndexedvEXT: {
			GlCmdGetPointerIndexedvEXT* pCC = (GlCmdGetPointerIndexedvEXT*)pCmd;
			glGetPointerIndexedvEXT(pCC->mTarget, pCC->mIndex, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_EnableIndexedEXT: {
			GlCmdEnableIndexedEXT* pCC = (GlCmdEnableIndexedEXT*)pCmd;
			glEnableIndexedEXT(pCC->mTarget, pCC->mIndex);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DisableIndexedEXT: {
			GlCmdDisableIndexedEXT* pCC = (GlCmdDisableIndexedEXT*)pCmd;
			glDisableIndexedEXT(pCC->mTarget, pCC->mIndex);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_IsEnabledIndexedEXT: {
			GlCmdIsEnabledIndexedEXT* pCC = (GlCmdIsEnabledIndexedEXT*)pCmd;
			glIsEnabledIndexedEXT(pCC->mTarget, pCC->mIndex);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetIntegerIndexedvEXT: {
			GlCmdGetIntegerIndexedvEXT* pCC = (GlCmdGetIntegerIndexedvEXT*)pCmd;
			glGetIntegerIndexedvEXT(pCC->mTarget, pCC->mIndex, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetBooleanIndexedvEXT: {
			GlCmdGetBooleanIndexedvEXT* pCC = (GlCmdGetBooleanIndexedvEXT*)pCmd;
			glGetBooleanIndexedvEXT(pCC->mTarget, pCC->mIndex, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CompressedTextureImage3DEXT: {
			GlCmdCompressedTextureImage3DEXT* pCC = (GlCmdCompressedTextureImage3DEXT*)pCmd;
			glCompressedTextureImage3DEXT(pCC->mTexture, pCC->mTarget, pCC->mLevel, pCC->mInternalformat, pCC->mWidth, pCC->mHeight, pCC->mDepth, pCC->mBorder, pCC->mImagesize, pCC->mBits);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CompressedTextureImage2DEXT: {
			GlCmdCompressedTextureImage2DEXT* pCC = (GlCmdCompressedTextureImage2DEXT*)pCmd;
			glCompressedTextureImage2DEXT(pCC->mTexture, pCC->mTarget, pCC->mLevel, pCC->mInternalformat, pCC->mWidth, pCC->mHeight, pCC->mBorder, pCC->mImagesize, pCC->mBits);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CompressedTextureImage1DEXT: {
			GlCmdCompressedTextureImage1DEXT* pCC = (GlCmdCompressedTextureImage1DEXT*)pCmd;
			glCompressedTextureImage1DEXT(pCC->mTexture, pCC->mTarget, pCC->mLevel, pCC->mInternalformat, pCC->mWidth, pCC->mBorder, pCC->mImagesize, pCC->mBits);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CompressedTextureSubImage3DEXT: {
			GlCmdCompressedTextureSubImage3DEXT* pCC = (GlCmdCompressedTextureSubImage3DEXT*)pCmd;
			glCompressedTextureSubImage3DEXT(pCC->mTexture, pCC->mTarget, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mZoffset, pCC->mWidth, pCC->mHeight, pCC->mDepth, pCC->mFormat, pCC->mImagesize, pCC->mBits);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CompressedTextureSubImage2DEXT: {
			GlCmdCompressedTextureSubImage2DEXT* pCC = (GlCmdCompressedTextureSubImage2DEXT*)pCmd;
			glCompressedTextureSubImage2DEXT(pCC->mTexture, pCC->mTarget, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mWidth, pCC->mHeight, pCC->mFormat, pCC->mImagesize, pCC->mBits);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CompressedTextureSubImage1DEXT: {
			GlCmdCompressedTextureSubImage1DEXT* pCC = (GlCmdCompressedTextureSubImage1DEXT*)pCmd;
			glCompressedTextureSubImage1DEXT(pCC->mTexture, pCC->mTarget, pCC->mLevel, pCC->mXoffset, pCC->mWidth, pCC->mFormat, pCC->mImagesize, pCC->mBits);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetCompressedTextureImageEXT: {
			GlCmdGetCompressedTextureImageEXT* pCC = (GlCmdGetCompressedTextureImageEXT*)pCmd;
			glGetCompressedTextureImageEXT(pCC->mTexture, pCC->mTarget, pCC->mLod, pCC->mImg);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CompressedMultiTexImage3DEXT: {
			GlCmdCompressedMultiTexImage3DEXT* pCC = (GlCmdCompressedMultiTexImage3DEXT*)pCmd;
			glCompressedMultiTexImage3DEXT(pCC->mTexunit, pCC->mTarget, pCC->mLevel, pCC->mInternalformat, pCC->mWidth, pCC->mHeight, pCC->mDepth, pCC->mBorder, pCC->mImagesize, pCC->mBits);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CompressedMultiTexImage2DEXT: {
			GlCmdCompressedMultiTexImage2DEXT* pCC = (GlCmdCompressedMultiTexImage2DEXT*)pCmd;
			glCompressedMultiTexImage2DEXT(pCC->mTexunit, pCC->mTarget, pCC->mLevel, pCC->mInternalformat, pCC->mWidth, pCC->mHeight, pCC->mBorder, pCC->mImagesize, pCC->mBits);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CompressedMultiTexImage1DEXT: {
			GlCmdCompressedMultiTexImage1DEXT* pCC = (GlCmdCompressedMultiTexImage1DEXT*)pCmd;
			glCompressedMultiTexImage1DEXT(pCC->mTexunit, pCC->mTarget, pCC->mLevel, pCC->mInternalformat, pCC->mWidth, pCC->mBorder, pCC->mImagesize, pCC->mBits);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CompressedMultiTexSubImage3DEXT: {
			GlCmdCompressedMultiTexSubImage3DEXT* pCC = (GlCmdCompressedMultiTexSubImage3DEXT*)pCmd;
			glCompressedMultiTexSubImage3DEXT(pCC->mTexunit, pCC->mTarget, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mZoffset, pCC->mWidth, pCC->mHeight, pCC->mDepth, pCC->mFormat, pCC->mImagesize, pCC->mBits);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CompressedMultiTexSubImage2DEXT: {
			GlCmdCompressedMultiTexSubImage2DEXT* pCC = (GlCmdCompressedMultiTexSubImage2DEXT*)pCmd;
			glCompressedMultiTexSubImage2DEXT(pCC->mTexunit, pCC->mTarget, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mWidth, pCC->mHeight, pCC->mFormat, pCC->mImagesize, pCC->mBits);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CompressedMultiTexSubImage1DEXT: {
			GlCmdCompressedMultiTexSubImage1DEXT* pCC = (GlCmdCompressedMultiTexSubImage1DEXT*)pCmd;
			glCompressedMultiTexSubImage1DEXT(pCC->mTexunit, pCC->mTarget, pCC->mLevel, pCC->mXoffset, pCC->mWidth, pCC->mFormat, pCC->mImagesize, pCC->mBits);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetCompressedMultiTexImageEXT: {
			GlCmdGetCompressedMultiTexImageEXT* pCC = (GlCmdGetCompressedMultiTexImageEXT*)pCmd;
			glGetCompressedMultiTexImageEXT(pCC->mTexunit, pCC->mTarget, pCC->mLod, pCC->mImg);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MatrixLoadTransposefEXT: {
			GlCmdMatrixLoadTransposefEXT* pCC = (GlCmdMatrixLoadTransposefEXT*)pCmd;
			glMatrixLoadTransposefEXT(pCC->mMode, pCC->mM);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MatrixLoadTransposedEXT: {
			GlCmdMatrixLoadTransposedEXT* pCC = (GlCmdMatrixLoadTransposedEXT*)pCmd;
			glMatrixLoadTransposedEXT(pCC->mMode, pCC->mM);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MatrixMultTransposefEXT: {
			GlCmdMatrixMultTransposefEXT* pCC = (GlCmdMatrixMultTransposefEXT*)pCmd;
			glMatrixMultTransposefEXT(pCC->mMode, pCC->mM);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MatrixMultTransposedEXT: {
			GlCmdMatrixMultTransposedEXT* pCC = (GlCmdMatrixMultTransposedEXT*)pCmd;
			glMatrixMultTransposedEXT(pCC->mMode, pCC->mM);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedBufferDataEXT: {
			GlCmdNamedBufferDataEXT* pCC = (GlCmdNamedBufferDataEXT*)pCmd;
			glNamedBufferDataEXT(pCC->mBuffer, pCC->mSize, pCC->mData, pCC->mUsage);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedBufferSubDataEXT: {
			GlCmdNamedBufferSubDataEXT* pCC = (GlCmdNamedBufferSubDataEXT*)pCmd;
			glNamedBufferSubDataEXT(pCC->mBuffer, pCC->mOffset, pCC->mSize, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MapNamedBufferEXT: {
			GlCmdMapNamedBufferEXT* pCC = (GlCmdMapNamedBufferEXT*)pCmd;
			glMapNamedBufferEXT(pCC->mBuffer, pCC->mAccess);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_UnmapNamedBufferEXT: {
			GlCmdUnmapNamedBufferEXT* pCC = (GlCmdUnmapNamedBufferEXT*)pCmd;
			glUnmapNamedBufferEXT(pCC->mBuffer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetNamedBufferParameterivEXT: {
			GlCmdGetNamedBufferParameterivEXT* pCC = (GlCmdGetNamedBufferParameterivEXT*)pCmd;
			glGetNamedBufferParameterivEXT(pCC->mBuffer, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetNamedBufferPointervEXT: {
			GlCmdGetNamedBufferPointervEXT* pCC = (GlCmdGetNamedBufferPointervEXT*)pCmd;
			glGetNamedBufferPointervEXT(pCC->mBuffer, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetNamedBufferSubDataEXT: {
			GlCmdGetNamedBufferSubDataEXT* pCC = (GlCmdGetNamedBufferSubDataEXT*)pCmd;
			glGetNamedBufferSubDataEXT(pCC->mBuffer, pCC->mOffset, pCC->mSize, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform1fEXT: {
			GlCmdProgramUniform1fEXT* pCC = (GlCmdProgramUniform1fEXT*)pCmd;
			glProgramUniform1fEXT(pCC->mProgram, pCC->mLocation, pCC->mV0);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform2fEXT: {
			GlCmdProgramUniform2fEXT* pCC = (GlCmdProgramUniform2fEXT*)pCmd;
			glProgramUniform2fEXT(pCC->mProgram, pCC->mLocation, pCC->mV0, pCC->mV1);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform3fEXT: {
			GlCmdProgramUniform3fEXT* pCC = (GlCmdProgramUniform3fEXT*)pCmd;
			glProgramUniform3fEXT(pCC->mProgram, pCC->mLocation, pCC->mV0, pCC->mV1, pCC->mV2);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform4fEXT: {
			GlCmdProgramUniform4fEXT* pCC = (GlCmdProgramUniform4fEXT*)pCmd;
			glProgramUniform4fEXT(pCC->mProgram, pCC->mLocation, pCC->mV0, pCC->mV1, pCC->mV2, pCC->mV3);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform1iEXT: {
			GlCmdProgramUniform1iEXT* pCC = (GlCmdProgramUniform1iEXT*)pCmd;
			glProgramUniform1iEXT(pCC->mProgram, pCC->mLocation, pCC->mV0);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform2iEXT: {
			GlCmdProgramUniform2iEXT* pCC = (GlCmdProgramUniform2iEXT*)pCmd;
			glProgramUniform2iEXT(pCC->mProgram, pCC->mLocation, pCC->mV0, pCC->mV1);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform3iEXT: {
			GlCmdProgramUniform3iEXT* pCC = (GlCmdProgramUniform3iEXT*)pCmd;
			glProgramUniform3iEXT(pCC->mProgram, pCC->mLocation, pCC->mV0, pCC->mV1, pCC->mV2);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform4iEXT: {
			GlCmdProgramUniform4iEXT* pCC = (GlCmdProgramUniform4iEXT*)pCmd;
			glProgramUniform4iEXT(pCC->mProgram, pCC->mLocation, pCC->mV0, pCC->mV1, pCC->mV2, pCC->mV3);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform1fvEXT: {
			GlCmdProgramUniform1fvEXT* pCC = (GlCmdProgramUniform1fvEXT*)pCmd;
			glProgramUniform1fvEXT(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform2fvEXT: {
			GlCmdProgramUniform2fvEXT* pCC = (GlCmdProgramUniform2fvEXT*)pCmd;
			glProgramUniform2fvEXT(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform3fvEXT: {
			GlCmdProgramUniform3fvEXT* pCC = (GlCmdProgramUniform3fvEXT*)pCmd;
			glProgramUniform3fvEXT(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform4fvEXT: {
			GlCmdProgramUniform4fvEXT* pCC = (GlCmdProgramUniform4fvEXT*)pCmd;
			glProgramUniform4fvEXT(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform1ivEXT: {
			GlCmdProgramUniform1ivEXT* pCC = (GlCmdProgramUniform1ivEXT*)pCmd;
			glProgramUniform1ivEXT(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform2ivEXT: {
			GlCmdProgramUniform2ivEXT* pCC = (GlCmdProgramUniform2ivEXT*)pCmd;
			glProgramUniform2ivEXT(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform3ivEXT: {
			GlCmdProgramUniform3ivEXT* pCC = (GlCmdProgramUniform3ivEXT*)pCmd;
			glProgramUniform3ivEXT(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform4ivEXT: {
			GlCmdProgramUniform4ivEXT* pCC = (GlCmdProgramUniform4ivEXT*)pCmd;
			glProgramUniform4ivEXT(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniformMatrix2fvEXT: {
			GlCmdProgramUniformMatrix2fvEXT* pCC = (GlCmdProgramUniformMatrix2fvEXT*)pCmd;
			glProgramUniformMatrix2fvEXT(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniformMatrix3fvEXT: {
			GlCmdProgramUniformMatrix3fvEXT* pCC = (GlCmdProgramUniformMatrix3fvEXT*)pCmd;
			glProgramUniformMatrix3fvEXT(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniformMatrix4fvEXT: {
			GlCmdProgramUniformMatrix4fvEXT* pCC = (GlCmdProgramUniformMatrix4fvEXT*)pCmd;
			glProgramUniformMatrix4fvEXT(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniformMatrix2x3fvEXT: {
			GlCmdProgramUniformMatrix2x3fvEXT* pCC = (GlCmdProgramUniformMatrix2x3fvEXT*)pCmd;
			glProgramUniformMatrix2x3fvEXT(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniformMatrix3x2fvEXT: {
			GlCmdProgramUniformMatrix3x2fvEXT* pCC = (GlCmdProgramUniformMatrix3x2fvEXT*)pCmd;
			glProgramUniformMatrix3x2fvEXT(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniformMatrix2x4fvEXT: {
			GlCmdProgramUniformMatrix2x4fvEXT* pCC = (GlCmdProgramUniformMatrix2x4fvEXT*)pCmd;
			glProgramUniformMatrix2x4fvEXT(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniformMatrix4x2fvEXT: {
			GlCmdProgramUniformMatrix4x2fvEXT* pCC = (GlCmdProgramUniformMatrix4x2fvEXT*)pCmd;
			glProgramUniformMatrix4x2fvEXT(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniformMatrix3x4fvEXT: {
			GlCmdProgramUniformMatrix3x4fvEXT* pCC = (GlCmdProgramUniformMatrix3x4fvEXT*)pCmd;
			glProgramUniformMatrix3x4fvEXT(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniformMatrix4x3fvEXT: {
			GlCmdProgramUniformMatrix4x3fvEXT* pCC = (GlCmdProgramUniformMatrix4x3fvEXT*)pCmd;
			glProgramUniformMatrix4x3fvEXT(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mTranspose, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureBufferEXT: {
			GlCmdTextureBufferEXT* pCC = (GlCmdTextureBufferEXT*)pCmd;
			glTextureBufferEXT(pCC->mTexture, pCC->mTarget, pCC->mInternalformat, pCC->mBuffer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiTexBufferEXT: {
			GlCmdMultiTexBufferEXT* pCC = (GlCmdMultiTexBufferEXT*)pCmd;
			glMultiTexBufferEXT(pCC->mTexunit, pCC->mTarget, pCC->mInternalformat, pCC->mBuffer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureParameterIivEXT: {
			GlCmdTextureParameterIivEXT* pCC = (GlCmdTextureParameterIivEXT*)pCmd;
			glTextureParameterIivEXT(pCC->mTexture, pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureParameterIuivEXT: {
			GlCmdTextureParameterIuivEXT* pCC = (GlCmdTextureParameterIuivEXT*)pCmd;
			glTextureParameterIuivEXT(pCC->mTexture, pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetTextureParameterIivEXT: {
			GlCmdGetTextureParameterIivEXT* pCC = (GlCmdGetTextureParameterIivEXT*)pCmd;
			glGetTextureParameterIivEXT(pCC->mTexture, pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetTextureParameterIuivEXT: {
			GlCmdGetTextureParameterIuivEXT* pCC = (GlCmdGetTextureParameterIuivEXT*)pCmd;
			glGetTextureParameterIuivEXT(pCC->mTexture, pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiTexParameterIivEXT: {
			GlCmdMultiTexParameterIivEXT* pCC = (GlCmdMultiTexParameterIivEXT*)pCmd;
			glMultiTexParameterIivEXT(pCC->mTexunit, pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiTexParameterIuivEXT: {
			GlCmdMultiTexParameterIuivEXT* pCC = (GlCmdMultiTexParameterIuivEXT*)pCmd;
			glMultiTexParameterIuivEXT(pCC->mTexunit, pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetMultiTexParameterIivEXT: {
			GlCmdGetMultiTexParameterIivEXT* pCC = (GlCmdGetMultiTexParameterIivEXT*)pCmd;
			glGetMultiTexParameterIivEXT(pCC->mTexunit, pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetMultiTexParameterIuivEXT: {
			GlCmdGetMultiTexParameterIuivEXT* pCC = (GlCmdGetMultiTexParameterIuivEXT*)pCmd;
			glGetMultiTexParameterIuivEXT(pCC->mTexunit, pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform1uiEXT: {
			GlCmdProgramUniform1uiEXT* pCC = (GlCmdProgramUniform1uiEXT*)pCmd;
			glProgramUniform1uiEXT(pCC->mProgram, pCC->mLocation, pCC->mV0);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform2uiEXT: {
			GlCmdProgramUniform2uiEXT* pCC = (GlCmdProgramUniform2uiEXT*)pCmd;
			glProgramUniform2uiEXT(pCC->mProgram, pCC->mLocation, pCC->mV0, pCC->mV1);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform3uiEXT: {
			GlCmdProgramUniform3uiEXT* pCC = (GlCmdProgramUniform3uiEXT*)pCmd;
			glProgramUniform3uiEXT(pCC->mProgram, pCC->mLocation, pCC->mV0, pCC->mV1, pCC->mV2);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform4uiEXT: {
			GlCmdProgramUniform4uiEXT* pCC = (GlCmdProgramUniform4uiEXT*)pCmd;
			glProgramUniform4uiEXT(pCC->mProgram, pCC->mLocation, pCC->mV0, pCC->mV1, pCC->mV2, pCC->mV3);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform1uivEXT: {
			GlCmdProgramUniform1uivEXT* pCC = (GlCmdProgramUniform1uivEXT*)pCmd;
			glProgramUniform1uivEXT(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform2uivEXT: {
			GlCmdProgramUniform2uivEXT* pCC = (GlCmdProgramUniform2uivEXT*)pCmd;
			glProgramUniform2uivEXT(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform3uivEXT: {
			GlCmdProgramUniform3uivEXT* pCC = (GlCmdProgramUniform3uivEXT*)pCmd;
			glProgramUniform3uivEXT(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ProgramUniform4uivEXT: {
			GlCmdProgramUniform4uivEXT* pCC = (GlCmdProgramUniform4uivEXT*)pCmd;
			glProgramUniform4uivEXT(pCC->mProgram, pCC->mLocation, pCC->mCount, pCC->mValue);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedProgramLocalParameters4fvEXT: {
			GlCmdNamedProgramLocalParameters4fvEXT* pCC = (GlCmdNamedProgramLocalParameters4fvEXT*)pCmd;
			glNamedProgramLocalParameters4fvEXT(pCC->mProgram, pCC->mTarget, pCC->mIndex, pCC->mCount, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedProgramLocalParameterI4iEXT: {
			GlCmdNamedProgramLocalParameterI4iEXT* pCC = (GlCmdNamedProgramLocalParameterI4iEXT*)pCmd;
			glNamedProgramLocalParameterI4iEXT(pCC->mProgram, pCC->mTarget, pCC->mIndex, pCC->mX, pCC->mY, pCC->mZ, pCC->mW);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedProgramLocalParameterI4ivEXT: {
			GlCmdNamedProgramLocalParameterI4ivEXT* pCC = (GlCmdNamedProgramLocalParameterI4ivEXT*)pCmd;
			glNamedProgramLocalParameterI4ivEXT(pCC->mProgram, pCC->mTarget, pCC->mIndex, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedProgramLocalParametersI4ivEXT: {
			GlCmdNamedProgramLocalParametersI4ivEXT* pCC = (GlCmdNamedProgramLocalParametersI4ivEXT*)pCmd;
			glNamedProgramLocalParametersI4ivEXT(pCC->mProgram, pCC->mTarget, pCC->mIndex, pCC->mCount, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedProgramLocalParameterI4uiEXT: {
			GlCmdNamedProgramLocalParameterI4uiEXT* pCC = (GlCmdNamedProgramLocalParameterI4uiEXT*)pCmd;
			glNamedProgramLocalParameterI4uiEXT(pCC->mProgram, pCC->mTarget, pCC->mIndex, pCC->mX, pCC->mY, pCC->mZ, pCC->mW);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedProgramLocalParameterI4uivEXT: {
			GlCmdNamedProgramLocalParameterI4uivEXT* pCC = (GlCmdNamedProgramLocalParameterI4uivEXT*)pCmd;
			glNamedProgramLocalParameterI4uivEXT(pCC->mProgram, pCC->mTarget, pCC->mIndex, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedProgramLocalParametersI4uivEXT: {
			GlCmdNamedProgramLocalParametersI4uivEXT* pCC = (GlCmdNamedProgramLocalParametersI4uivEXT*)pCmd;
			glNamedProgramLocalParametersI4uivEXT(pCC->mProgram, pCC->mTarget, pCC->mIndex, pCC->mCount, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetNamedProgramLocalParameterIivEXT: {
			GlCmdGetNamedProgramLocalParameterIivEXT* pCC = (GlCmdGetNamedProgramLocalParameterIivEXT*)pCmd;
			glGetNamedProgramLocalParameterIivEXT(pCC->mProgram, pCC->mTarget, pCC->mIndex, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetNamedProgramLocalParameterIuivEXT: {
			GlCmdGetNamedProgramLocalParameterIuivEXT* pCC = (GlCmdGetNamedProgramLocalParameterIuivEXT*)pCmd;
			glGetNamedProgramLocalParameterIuivEXT(pCC->mProgram, pCC->mTarget, pCC->mIndex, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_EnableClientStateiEXT: {
			GlCmdEnableClientStateiEXT* pCC = (GlCmdEnableClientStateiEXT*)pCmd;
			glEnableClientStateiEXT(pCC->mArray, pCC->mIndex);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DisableClientStateiEXT: {
			GlCmdDisableClientStateiEXT* pCC = (GlCmdDisableClientStateiEXT*)pCmd;
			glDisableClientStateiEXT(pCC->mArray, pCC->mIndex);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetFloati_vEXT: {
			GlCmdGetFloati_vEXT* pCC = (GlCmdGetFloati_vEXT*)pCmd;
			glGetFloati_vEXT(pCC->mPname, pCC->mIndex, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetDoublei_vEXT: {
			GlCmdGetDoublei_vEXT* pCC = (GlCmdGetDoublei_vEXT*)pCmd;
			glGetDoublei_vEXT(pCC->mPname, pCC->mIndex, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetPointeri_vEXT: {
			GlCmdGetPointeri_vEXT* pCC = (GlCmdGetPointeri_vEXT*)pCmd;
			glGetPointeri_vEXT(pCC->mPname, pCC->mIndex, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedProgramStringEXT: {
			GlCmdNamedProgramStringEXT* pCC = (GlCmdNamedProgramStringEXT*)pCmd;
			glNamedProgramStringEXT(pCC->mProgram, pCC->mTarget, pCC->mFormat, pCC->mLen, pCC->mString);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedProgramLocalParameter4dEXT: {
			GlCmdNamedProgramLocalParameter4dEXT* pCC = (GlCmdNamedProgramLocalParameter4dEXT*)pCmd;
			glNamedProgramLocalParameter4dEXT(pCC->mProgram, pCC->mTarget, pCC->mIndex, pCC->mX, pCC->mY, pCC->mZ, pCC->mW);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedProgramLocalParameter4dvEXT: {
			GlCmdNamedProgramLocalParameter4dvEXT* pCC = (GlCmdNamedProgramLocalParameter4dvEXT*)pCmd;
			glNamedProgramLocalParameter4dvEXT(pCC->mProgram, pCC->mTarget, pCC->mIndex, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedProgramLocalParameter4fEXT: {
			GlCmdNamedProgramLocalParameter4fEXT* pCC = (GlCmdNamedProgramLocalParameter4fEXT*)pCmd;
			glNamedProgramLocalParameter4fEXT(pCC->mProgram, pCC->mTarget, pCC->mIndex, pCC->mX, pCC->mY, pCC->mZ, pCC->mW);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedProgramLocalParameter4fvEXT: {
			GlCmdNamedProgramLocalParameter4fvEXT* pCC = (GlCmdNamedProgramLocalParameter4fvEXT*)pCmd;
			glNamedProgramLocalParameter4fvEXT(pCC->mProgram, pCC->mTarget, pCC->mIndex, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetNamedProgramLocalParameterdvEXT: {
			GlCmdGetNamedProgramLocalParameterdvEXT* pCC = (GlCmdGetNamedProgramLocalParameterdvEXT*)pCmd;
			glGetNamedProgramLocalParameterdvEXT(pCC->mProgram, pCC->mTarget, pCC->mIndex, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetNamedProgramLocalParameterfvEXT: {
			GlCmdGetNamedProgramLocalParameterfvEXT* pCC = (GlCmdGetNamedProgramLocalParameterfvEXT*)pCmd;
			glGetNamedProgramLocalParameterfvEXT(pCC->mProgram, pCC->mTarget, pCC->mIndex, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetNamedProgramivEXT: {
			GlCmdGetNamedProgramivEXT* pCC = (GlCmdGetNamedProgramivEXT*)pCmd;
			glGetNamedProgramivEXT(pCC->mProgram, pCC->mTarget, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetNamedProgramStringEXT: {
			GlCmdGetNamedProgramStringEXT* pCC = (GlCmdGetNamedProgramStringEXT*)pCmd;
			glGetNamedProgramStringEXT(pCC->mProgram, pCC->mTarget, pCC->mPname, pCC->mString);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedRenderbufferStorageEXT: {
			GlCmdNamedRenderbufferStorageEXT* pCC = (GlCmdNamedRenderbufferStorageEXT*)pCmd;
			glNamedRenderbufferStorageEXT(pCC->mRenderbuffer, pCC->mInternalformat, pCC->mWidth, pCC->mHeight);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetNamedRenderbufferParameterivEXT: {
			GlCmdGetNamedRenderbufferParameterivEXT* pCC = (GlCmdGetNamedRenderbufferParameterivEXT*)pCmd;
			glGetNamedRenderbufferParameterivEXT(pCC->mRenderbuffer, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedRenderbufferStorageMultisampleEXT: {
			GlCmdNamedRenderbufferStorageMultisampleEXT* pCC = (GlCmdNamedRenderbufferStorageMultisampleEXT*)pCmd;
			glNamedRenderbufferStorageMultisampleEXT(pCC->mRenderbuffer, pCC->mSamples, pCC->mInternalformat, pCC->mWidth, pCC->mHeight);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedRenderbufferStorageMultisampleCoverageEXT: {
			GlCmdNamedRenderbufferStorageMultisampleCoverageEXT* pCC = (GlCmdNamedRenderbufferStorageMultisampleCoverageEXT*)pCmd;
			glNamedRenderbufferStorageMultisampleCoverageEXT(pCC->mRenderbuffer, pCC->mCoveragesamples, pCC->mColorsamples, pCC->mInternalformat, pCC->mWidth, pCC->mHeight);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CheckNamedFramebufferStatusEXT: {
			GlCmdCheckNamedFramebufferStatusEXT* pCC = (GlCmdCheckNamedFramebufferStatusEXT*)pCmd;
			glCheckNamedFramebufferStatusEXT(pCC->mFramebuffer, pCC->mTarget);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedFramebufferTexture1DEXT: {
			GlCmdNamedFramebufferTexture1DEXT* pCC = (GlCmdNamedFramebufferTexture1DEXT*)pCmd;
			glNamedFramebufferTexture1DEXT(pCC->mFramebuffer, pCC->mAttachment, pCC->mTextarget, pCC->mTexture, pCC->mLevel);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedFramebufferTexture2DEXT: {
			GlCmdNamedFramebufferTexture2DEXT* pCC = (GlCmdNamedFramebufferTexture2DEXT*)pCmd;
			glNamedFramebufferTexture2DEXT(pCC->mFramebuffer, pCC->mAttachment, pCC->mTextarget, pCC->mTexture, pCC->mLevel);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedFramebufferTexture3DEXT: {
			GlCmdNamedFramebufferTexture3DEXT* pCC = (GlCmdNamedFramebufferTexture3DEXT*)pCmd;
			glNamedFramebufferTexture3DEXT(pCC->mFramebuffer, pCC->mAttachment, pCC->mTextarget, pCC->mTexture, pCC->mLevel, pCC->mZoffset);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedFramebufferRenderbufferEXT: {
			GlCmdNamedFramebufferRenderbufferEXT* pCC = (GlCmdNamedFramebufferRenderbufferEXT*)pCmd;
			glNamedFramebufferRenderbufferEXT(pCC->mFramebuffer, pCC->mAttachment, pCC->mRenderbuffertarget, pCC->mRenderbuffer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetNamedFramebufferAttachmentParameterivEXT: {
			GlCmdGetNamedFramebufferAttachmentParameterivEXT* pCC = (GlCmdGetNamedFramebufferAttachmentParameterivEXT*)pCmd;
			glGetNamedFramebufferAttachmentParameterivEXT(pCC->mFramebuffer, pCC->mAttachment, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GenerateTextureMipmapEXT: {
			GlCmdGenerateTextureMipmapEXT* pCC = (GlCmdGenerateTextureMipmapEXT*)pCmd;
			glGenerateTextureMipmapEXT(pCC->mTexture, pCC->mTarget);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GenerateMultiTexMipmapEXT: {
			GlCmdGenerateMultiTexMipmapEXT* pCC = (GlCmdGenerateMultiTexMipmapEXT*)pCmd;
			glGenerateMultiTexMipmapEXT(pCC->mTexunit, pCC->mTarget);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_FramebufferDrawBufferEXT: {
			GlCmdFramebufferDrawBufferEXT* pCC = (GlCmdFramebufferDrawBufferEXT*)pCmd;
			glFramebufferDrawBufferEXT(pCC->mFramebuffer, pCC->mMode);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_FramebufferDrawBuffersEXT: {
			GlCmdFramebufferDrawBuffersEXT* pCC = (GlCmdFramebufferDrawBuffersEXT*)pCmd;
			glFramebufferDrawBuffersEXT(pCC->mFramebuffer, pCC->mN, pCC->mBufs);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_FramebufferReadBufferEXT: {
			GlCmdFramebufferReadBufferEXT* pCC = (GlCmdFramebufferReadBufferEXT*)pCmd;
			glFramebufferReadBufferEXT(pCC->mFramebuffer, pCC->mMode);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetFramebufferParameterivEXT: {
			GlCmdGetFramebufferParameterivEXT* pCC = (GlCmdGetFramebufferParameterivEXT*)pCmd;
			glGetFramebufferParameterivEXT(pCC->mFramebuffer, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedCopyBufferSubDataEXT: {
			GlCmdNamedCopyBufferSubDataEXT* pCC = (GlCmdNamedCopyBufferSubDataEXT*)pCmd;
			glNamedCopyBufferSubDataEXT(pCC->mReadbuffer, pCC->mWritebuffer, pCC->mReadoffset, pCC->mWriteoffset, pCC->mSize);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedFramebufferTextureEXT: {
			GlCmdNamedFramebufferTextureEXT* pCC = (GlCmdNamedFramebufferTextureEXT*)pCmd;
			glNamedFramebufferTextureEXT(pCC->mFramebuffer, pCC->mAttachment, pCC->mTexture, pCC->mLevel);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedFramebufferTextureLayerEXT: {
			GlCmdNamedFramebufferTextureLayerEXT* pCC = (GlCmdNamedFramebufferTextureLayerEXT*)pCmd;
			glNamedFramebufferTextureLayerEXT(pCC->mFramebuffer, pCC->mAttachment, pCC->mTexture, pCC->mLevel, pCC->mLayer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedFramebufferTextureFaceEXT: {
			GlCmdNamedFramebufferTextureFaceEXT* pCC = (GlCmdNamedFramebufferTextureFaceEXT*)pCmd;
			glNamedFramebufferTextureFaceEXT(pCC->mFramebuffer, pCC->mAttachment, pCC->mTexture, pCC->mLevel, pCC->mFace);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureRenderbufferEXT: {
			GlCmdTextureRenderbufferEXT* pCC = (GlCmdTextureRenderbufferEXT*)pCmd;
			glTextureRenderbufferEXT(pCC->mTexture, pCC->mTarget, pCC->mRenderbuffer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MultiTexRenderbufferEXT: {
			GlCmdMultiTexRenderbufferEXT* pCC = (GlCmdMultiTexRenderbufferEXT*)pCmd;
			glMultiTexRenderbufferEXT(pCC->mTexunit, pCC->mTarget, pCC->mRenderbuffer);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexArrayVertexOffsetEXT: {
			GlCmdVertexArrayVertexOffsetEXT* pCC = (GlCmdVertexArrayVertexOffsetEXT*)pCmd;
			glVertexArrayVertexOffsetEXT(pCC->mVaobj, pCC->mBuffer, pCC->mSize, pCC->mType, pCC->mStride, pCC->mOffset);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexArrayColorOffsetEXT: {
			GlCmdVertexArrayColorOffsetEXT* pCC = (GlCmdVertexArrayColorOffsetEXT*)pCmd;
			glVertexArrayColorOffsetEXT(pCC->mVaobj, pCC->mBuffer, pCC->mSize, pCC->mType, pCC->mStride, pCC->mOffset);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexArrayEdgeFlagOffsetEXT: {
			GlCmdVertexArrayEdgeFlagOffsetEXT* pCC = (GlCmdVertexArrayEdgeFlagOffsetEXT*)pCmd;
			glVertexArrayEdgeFlagOffsetEXT(pCC->mVaobj, pCC->mBuffer, pCC->mStride, pCC->mOffset);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexArrayIndexOffsetEXT: {
			GlCmdVertexArrayIndexOffsetEXT* pCC = (GlCmdVertexArrayIndexOffsetEXT*)pCmd;
			glVertexArrayIndexOffsetEXT(pCC->mVaobj, pCC->mBuffer, pCC->mType, pCC->mStride, pCC->mOffset);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexArrayNormalOffsetEXT: {
			GlCmdVertexArrayNormalOffsetEXT* pCC = (GlCmdVertexArrayNormalOffsetEXT*)pCmd;
			glVertexArrayNormalOffsetEXT(pCC->mVaobj, pCC->mBuffer, pCC->mType, pCC->mStride, pCC->mOffset);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexArrayTexCoordOffsetEXT: {
			GlCmdVertexArrayTexCoordOffsetEXT* pCC = (GlCmdVertexArrayTexCoordOffsetEXT*)pCmd;
			glVertexArrayTexCoordOffsetEXT(pCC->mVaobj, pCC->mBuffer, pCC->mSize, pCC->mType, pCC->mStride, pCC->mOffset);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexArrayMultiTexCoordOffsetEXT: {
			GlCmdVertexArrayMultiTexCoordOffsetEXT* pCC = (GlCmdVertexArrayMultiTexCoordOffsetEXT*)pCmd;
			glVertexArrayMultiTexCoordOffsetEXT(pCC->mVaobj, pCC->mBuffer, pCC->mTexunit, pCC->mSize, pCC->mType, pCC->mStride, pCC->mOffset);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexArrayFogCoordOffsetEXT: {
			GlCmdVertexArrayFogCoordOffsetEXT* pCC = (GlCmdVertexArrayFogCoordOffsetEXT*)pCmd;
			glVertexArrayFogCoordOffsetEXT(pCC->mVaobj, pCC->mBuffer, pCC->mType, pCC->mStride, pCC->mOffset);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexArraySecondaryColorOffsetEXT: {
			GlCmdVertexArraySecondaryColorOffsetEXT* pCC = (GlCmdVertexArraySecondaryColorOffsetEXT*)pCmd;
			glVertexArraySecondaryColorOffsetEXT(pCC->mVaobj, pCC->mBuffer, pCC->mSize, pCC->mType, pCC->mStride, pCC->mOffset);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexArrayVertexAttribOffsetEXT: {
			GlCmdVertexArrayVertexAttribOffsetEXT* pCC = (GlCmdVertexArrayVertexAttribOffsetEXT*)pCmd;
			glVertexArrayVertexAttribOffsetEXT(pCC->mVaobj, pCC->mBuffer, pCC->mIndex, pCC->mSize, pCC->mType, pCC->mNormalized, pCC->mStride, pCC->mOffset);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexArrayVertexAttribIOffsetEXT: {
			GlCmdVertexArrayVertexAttribIOffsetEXT* pCC = (GlCmdVertexArrayVertexAttribIOffsetEXT*)pCmd;
			glVertexArrayVertexAttribIOffsetEXT(pCC->mVaobj, pCC->mBuffer, pCC->mIndex, pCC->mSize, pCC->mType, pCC->mStride, pCC->mOffset);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_EnableVertexArrayEXT: {
			GlCmdEnableVertexArrayEXT* pCC = (GlCmdEnableVertexArrayEXT*)pCmd;
			glEnableVertexArrayEXT(pCC->mVaobj, pCC->mArray);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DisableVertexArrayEXT: {
			GlCmdDisableVertexArrayEXT* pCC = (GlCmdDisableVertexArrayEXT*)pCmd;
			glDisableVertexArrayEXT(pCC->mVaobj, pCC->mArray);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_EnableVertexArrayAttribEXT: {
			GlCmdEnableVertexArrayAttribEXT* pCC = (GlCmdEnableVertexArrayAttribEXT*)pCmd;
			glEnableVertexArrayAttribEXT(pCC->mVaobj, pCC->mIndex);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DisableVertexArrayAttribEXT: {
			GlCmdDisableVertexArrayAttribEXT* pCC = (GlCmdDisableVertexArrayAttribEXT*)pCmd;
			glDisableVertexArrayAttribEXT(pCC->mVaobj, pCC->mIndex);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetVertexArrayIntegervEXT: {
			GlCmdGetVertexArrayIntegervEXT* pCC = (GlCmdGetVertexArrayIntegervEXT*)pCmd;
			glGetVertexArrayIntegervEXT(pCC->mVaobj, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetVertexArrayPointervEXT: {
			GlCmdGetVertexArrayPointervEXT* pCC = (GlCmdGetVertexArrayPointervEXT*)pCmd;
			glGetVertexArrayPointervEXT(pCC->mVaobj, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetVertexArrayIntegeri_vEXT: {
			GlCmdGetVertexArrayIntegeri_vEXT* pCC = (GlCmdGetVertexArrayIntegeri_vEXT*)pCmd;
			glGetVertexArrayIntegeri_vEXT(pCC->mVaobj, pCC->mIndex, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetVertexArrayPointeri_vEXT: {
			GlCmdGetVertexArrayPointeri_vEXT* pCC = (GlCmdGetVertexArrayPointeri_vEXT*)pCmd;
			glGetVertexArrayPointeri_vEXT(pCC->mVaobj, pCC->mIndex, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_MapNamedBufferRangeEXT: {
			GlCmdMapNamedBufferRangeEXT* pCC = (GlCmdMapNamedBufferRangeEXT*)pCmd;
			glMapNamedBufferRangeEXT(pCC->mBuffer, pCC->mOffset, pCC->mLength, pCC->mAccess);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_FlushMappedNamedBufferRangeEXT: {
			GlCmdFlushMappedNamedBufferRangeEXT* pCC = (GlCmdFlushMappedNamedBufferRangeEXT*)pCmd;
			glFlushMappedNamedBufferRangeEXT(pCC->mBuffer, pCC->mOffset, pCC->mLength);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedBufferStorageEXT: {
			GlCmdNamedBufferStorageEXT* pCC = (GlCmdNamedBufferStorageEXT*)pCmd;
			glNamedBufferStorageEXT(pCC->mBuffer, pCC->mSize, pCC->mData, pCC->mFlags);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ClearNamedBufferDataEXT: {
			GlCmdClearNamedBufferDataEXT* pCC = (GlCmdClearNamedBufferDataEXT*)pCmd;
			glClearNamedBufferDataEXT(pCC->mBuffer, pCC->mInternalformat, pCC->mFormat, pCC->mType, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ClearNamedBufferSubDataEXT: {
			GlCmdClearNamedBufferSubDataEXT* pCC = (GlCmdClearNamedBufferSubDataEXT*)pCmd;
			glClearNamedBufferSubDataEXT(pCC->mBuffer, pCC->mInternalformat, pCC->mOffset, pCC->mSize, pCC->mFormat, pCC->mType, pCC->mData);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_NamedFramebufferParameteriEXT: {
			GlCmdNamedFramebufferParameteriEXT* pCC = (GlCmdNamedFramebufferParameteriEXT*)pCmd;
			glNamedFramebufferParameteriEXT(pCC->mFramebuffer, pCC->mPname, pCC->mParam);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetNamedFramebufferParameterivEXT: {
			GlCmdGetNamedFramebufferParameterivEXT* pCC = (GlCmdGetNamedFramebufferParameterivEXT*)pCmd;
			glGetNamedFramebufferParameterivEXT(pCC->mFramebuffer, pCC->mPname, pCC->mParams);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureBufferRangeEXT: {
			GlCmdTextureBufferRangeEXT* pCC = (GlCmdTextureBufferRangeEXT*)pCmd;
			glTextureBufferRangeEXT(pCC->mTexture, pCC->mTarget, pCC->mInternalformat, pCC->mBuffer, pCC->mOffset, pCC->mSize);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureStorage1DEXT: {
			GlCmdTextureStorage1DEXT* pCC = (GlCmdTextureStorage1DEXT*)pCmd;
			glTextureStorage1DEXT(pCC->mTexture, pCC->mTarget, pCC->mLevels, pCC->mInternalformat, pCC->mWidth);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureStorage2DEXT: {
			GlCmdTextureStorage2DEXT* pCC = (GlCmdTextureStorage2DEXT*)pCmd;
			glTextureStorage2DEXT(pCC->mTexture, pCC->mTarget, pCC->mLevels, pCC->mInternalformat, pCC->mWidth, pCC->mHeight);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureStorage3DEXT: {
			GlCmdTextureStorage3DEXT* pCC = (GlCmdTextureStorage3DEXT*)pCmd;
			glTextureStorage3DEXT(pCC->mTexture, pCC->mTarget, pCC->mLevels, pCC->mInternalformat, pCC->mWidth, pCC->mHeight, pCC->mDepth);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureStorage2DMultisampleEXT: {
			GlCmdTextureStorage2DMultisampleEXT* pCC = (GlCmdTextureStorage2DMultisampleEXT*)pCmd;
			glTextureStorage2DMultisampleEXT(pCC->mTexture, pCC->mTarget, pCC->mSamples, pCC->mInternalformat, pCC->mWidth, pCC->mHeight, pCC->mFixedsamplelocations);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TextureStorage3DMultisampleEXT: {
			GlCmdTextureStorage3DMultisampleEXT* pCC = (GlCmdTextureStorage3DMultisampleEXT*)pCmd;
			glTextureStorage3DMultisampleEXT(pCC->mTexture, pCC->mTarget, pCC->mSamples, pCC->mInternalformat, pCC->mWidth, pCC->mHeight, pCC->mDepth, pCC->mFixedsamplelocations);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexArrayBindVertexBufferEXT: {
			GlCmdVertexArrayBindVertexBufferEXT* pCC = (GlCmdVertexArrayBindVertexBufferEXT*)pCmd;
			glVertexArrayBindVertexBufferEXT(pCC->mVaobj, pCC->mBindingindex, pCC->mBuffer, pCC->mOffset, pCC->mStride);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexArrayVertexAttribFormatEXT: {
			GlCmdVertexArrayVertexAttribFormatEXT* pCC = (GlCmdVertexArrayVertexAttribFormatEXT*)pCmd;
			glVertexArrayVertexAttribFormatEXT(pCC->mVaobj, pCC->mAttribindex, pCC->mSize, pCC->mType, pCC->mNormalized, pCC->mRelativeoffset);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexArrayVertexAttribIFormatEXT: {
			GlCmdVertexArrayVertexAttribIFormatEXT* pCC = (GlCmdVertexArrayVertexAttribIFormatEXT*)pCmd;
			glVertexArrayVertexAttribIFormatEXT(pCC->mVaobj, pCC->mAttribindex, pCC->mSize, pCC->mType, pCC->mRelativeoffset);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexArrayVertexAttribLFormatEXT: {
			GlCmdVertexArrayVertexAttribLFormatEXT* pCC = (GlCmdVertexArrayVertexAttribLFormatEXT*)pCmd;
			glVertexArrayVertexAttribLFormatEXT(pCC->mVaobj, pCC->mAttribindex, pCC->mSize, pCC->mType, pCC->mRelativeoffset);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexArrayVertexAttribBindingEXT: {
			GlCmdVertexArrayVertexAttribBindingEXT* pCC = (GlCmdVertexArrayVertexAttribBindingEXT*)pCmd;
			glVertexArrayVertexAttribBindingEXT(pCC->mVaobj, pCC->mAttribindex, pCC->mBindingindex);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexArrayVertexBindingDivisorEXT: {
			GlCmdVertexArrayVertexBindingDivisorEXT* pCC = (GlCmdVertexArrayVertexBindingDivisorEXT*)pCmd;
			glVertexArrayVertexBindingDivisorEXT(pCC->mVaobj, pCC->mBindingindex, pCC->mDivisor);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexArrayVertexAttribLOffsetEXT: {
			GlCmdVertexArrayVertexAttribLOffsetEXT* pCC = (GlCmdVertexArrayVertexAttribLOffsetEXT*)pCmd;
			glVertexArrayVertexAttribLOffsetEXT(pCC->mVaobj, pCC->mBuffer, pCC->mIndex, pCC->mSize, pCC->mType, pCC->mStride, pCC->mOffset);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_TexturePageCommitmentEXT: {
			GlCmdTexturePageCommitmentEXT* pCC = (GlCmdTexturePageCommitmentEXT*)pCmd;
			glTexturePageCommitmentEXT(pCC->mTexture, pCC->mLevel, pCC->mXoffset, pCC->mYoffset, pCC->mZoffset, pCC->mWidth, pCC->mHeight, pCC->mDepth, pCC->mCommit);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_VertexArrayVertexAttribDivisorEXT: {
			GlCmdVertexArrayVertexAttribDivisorEXT* pCC = (GlCmdVertexArrayVertexAttribDivisorEXT*)pCmd;
			glVertexArrayVertexAttribDivisorEXT(pCC->mVaobj, pCC->mIndex, pCC->mDivisor);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DrawArraysInstancedEXT: {
			GlCmdDrawArraysInstancedEXT* pCC = (GlCmdDrawArraysInstancedEXT*)pCmd;
			glDrawArraysInstancedEXT(pCC->mMode, pCC->mStart, pCC->mCount, pCC->mPrimcount);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DrawElementsInstancedEXT: {
			GlCmdDrawElementsInstancedEXT* pCC = (GlCmdDrawElementsInstancedEXT*)pCmd;
			glDrawElementsInstancedEXT(pCC->mMode, pCC->mCount, pCC->mType, pCC->mIndices, pCC->mPrimcount);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_PolygonOffsetClampEXT: {
			GlCmdPolygonOffsetClampEXT* pCC = (GlCmdPolygonOffsetClampEXT*)pCmd;
			glPolygonOffsetClampEXT(pCC->mFactor, pCC->mUnits, pCC->mClamp);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_RasterSamplesEXT: {
			GlCmdRasterSamplesEXT* pCC = (GlCmdRasterSamplesEXT*)pCmd;
			glRasterSamplesEXT(pCC->mSamples, pCC->mFixedsamplelocations);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_UseShaderProgramEXT: {
			GlCmdUseShaderProgramEXT* pCC = (GlCmdUseShaderProgramEXT*)pCmd;
			glUseShaderProgramEXT(pCC->mType, pCC->mProgram);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ActiveProgramEXT: {
			GlCmdActiveProgramEXT* pCC = (GlCmdActiveProgramEXT*)pCmd;
			glActiveProgramEXT(pCC->mProgram);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CreateShaderProgramEXT: {
			GlCmdCreateShaderProgramEXT* pCC = (GlCmdCreateShaderProgramEXT*)pCmd;
			glCreateShaderProgramEXT(pCC->mType, pCC->mString);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_WindowRectanglesEXT: {
			GlCmdWindowRectanglesEXT* pCC = (GlCmdWindowRectanglesEXT*)pCmd;
			glWindowRectanglesEXT(pCC->mMode, pCC->mCount, pCC->mBox);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CreateStatesNV: {
			GlCmdCreateStatesNV* pCC = (GlCmdCreateStatesNV*)pCmd;
			glCreateStatesNV(pCC->mN, pCC->mStates);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DeleteStatesNV: {
			GlCmdDeleteStatesNV* pCC = (GlCmdDeleteStatesNV*)pCmd;
			glDeleteStatesNV(pCC->mN, pCC->mStates);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_IsStateNV: {
			GlCmdIsStateNV* pCC = (GlCmdIsStateNV*)pCmd;
			glIsStateNV(pCC->mState);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_StateCaptureNV: {
			GlCmdStateCaptureNV* pCC = (GlCmdStateCaptureNV*)pCmd;
			glStateCaptureNV(pCC->mState, pCC->mMode);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetCommandHeaderNV: {
			GlCmdGetCommandHeaderNV* pCC = (GlCmdGetCommandHeaderNV*)pCmd;
			glGetCommandHeaderNV(pCC->mTokenid, pCC->mSize);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_GetStageIndexNV: {
			GlCmdGetStageIndexNV* pCC = (GlCmdGetStageIndexNV*)pCmd;
			glGetStageIndexNV(pCC->mShadertype);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DrawCommandsNV: {
			GlCmdDrawCommandsNV* pCC = (GlCmdDrawCommandsNV*)pCmd;
			glDrawCommandsNV(pCC->mPrimitivemode, pCC->mBuffer, pCC->mIndirects, pCC->mSizes, pCC->mCount);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DrawCommandsAddressNV: {
			GlCmdDrawCommandsAddressNV* pCC = (GlCmdDrawCommandsAddressNV*)pCmd;
			glDrawCommandsAddressNV(pCC->mPrimitivemode, pCC->mIndirects, pCC->mSizes, pCC->mCount);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DrawCommandsStatesNV: {
			GlCmdDrawCommandsStatesNV* pCC = (GlCmdDrawCommandsStatesNV*)pCmd;
			glDrawCommandsStatesNV(pCC->mBuffer, pCC->mIndirects, pCC->mSizes, pCC->mStates, pCC->mFbos, pCC->mCount);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DrawCommandsStatesAddressNV: {
			GlCmdDrawCommandsStatesAddressNV* pCC = (GlCmdDrawCommandsStatesAddressNV*)pCmd;
			glDrawCommandsStatesAddressNV(pCC->mIndirects, pCC->mSizes, pCC->mStates, pCC->mFbos, pCC->mCount);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CreateCommandListsNV: {
			GlCmdCreateCommandListsNV* pCC = (GlCmdCreateCommandListsNV*)pCmd;
			glCreateCommandListsNV(pCC->mN, pCC->mLists);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_DeleteCommandListsNV: {
			GlCmdDeleteCommandListsNV* pCC = (GlCmdDeleteCommandListsNV*)pCmd;
			glDeleteCommandListsNV(pCC->mN, pCC->mLists);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_IsCommandListNV: {
			GlCmdIsCommandListNV* pCC = (GlCmdIsCommandListNV*)pCmd;
			glIsCommandListNV(pCC->mList);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_ListDrawCommandsStatesClientNV: {
			GlCmdListDrawCommandsStatesClientNV* pCC = (GlCmdListDrawCommandsStatesClientNV*)pCmd;
			glListDrawCommandsStatesClientNV(pCC->mList, pCC->mSegment, pCC->mIndirects, pCC->mSizes, pCC->mStates, pCC->mFbos, pCC->mCount);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CommandListSegmentsNV: {
			GlCmdCommandListSegmentsNV* pCC = (GlCmdCommandListSegmentsNV*)pCmd;
			glCommandListSegmentsNV(pCC->mList, pCC->mSegments);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CompileCommandListNV: {
			GlCmdCompileCommandListNV* pCC = (GlCmdCompileCommandListNV*)pCmd;
			glCompileCommandListNV(pCC->mList);
		} break;
		case GL_STRUCTURE_TYPE_COMMAND_CallCommandListNV: {
			GlCmdCallCommandListNV* pCC = (GlCmdCallCommandListNV*)pCmd;
			glCallCommandListNV(pCC->mList);
		} break;
		}
	}
}
