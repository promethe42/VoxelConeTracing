/*
 Copyright (c) 2012 The VCT Project

  This file is part of VoxelConeTracing and is an implementation of
  "Interactive Indirect Illumination Using Voxel Cone Tracing" by Crassin et al

  VoxelConeTracing is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  VoxelConeTracing is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with VoxelConeTracing.  If not, see <http://www.gnu.org/licenses/>.
*/

/*!
* \author Dominik Lazarek (dominik.lazarek@gmail.com)
* \author Andreas Weinmann (andy.weinmann@gmail.com)
*/

#ifndef VCT_SRC_VCT_DEBUGPASS_H_
#define VCT_SRC_VCT_DEBUGPASS_H_

#include "KoRE/Passes/ShaderProgramPass.h"
#include "VoxelConeTracing/Scene/VCTscene.h"
#include "KoRE/SceneManager.h"
#include "KoRE/RenderManager.h"
#include "KoRE/ResourceManager.h"

class DebugPass : public kore::ShaderProgramPass
{
public:
  DebugPass(VCTscene* vctScene, kore::EOperationExecutionType executionType);
  virtual ~DebugPass(void);

private:
  kore::RenderManager* _renderMgr;
  kore::SceneManager* _sceneMgr;
  kore::ResourceManager* _resMgr;

  kore::ShaderProgram _debugShader;
  VCTscene* _vctScene;

  void debugCleanup();
  void debugVoxelIndexAC();
  void debugVoxelFragmentList();
  void debugIndirectCmdBuff();
  void debugNodePool();
  void debugNextFreeAC();
  //void traverseOctree(const SNode* parent, uint level, uint maxLevel);
  void debugNodePool_Octree();
  void debugLevelAddressBuf();
  void debugBrickAc();
  void debugRadianceNodePool();
  void debugColorNodePool();
};
#endif //VCT_SRC_VCT_OCTREEVISPASS_H_
