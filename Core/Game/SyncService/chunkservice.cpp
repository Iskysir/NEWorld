// 
// Core: chunkservice.cpp
// NEWorld: A Free Game with Similar Rules to Minecraft.
// Copyright (C) 2015-2018 NEWorld Team
// 
// NEWorld is free software: you can redistribute it and/or modify it 
// under the terms of the GNU Lesser General Public License as published
// by the Free Software Foundation, either version 3 of the License, or 
// (at your option) any later version.
// 
// NEWorld is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
// or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General 
// Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with NEWorld.  If not, see <http://www.gnu.org/licenses/>.
// 

#include "chunkservice.hpp"
#include "Common/JsonHelper.h"
namespace {
    NW_MAKE_SERVICE(ChunkService, "org.newinfinideas.neworld.chunk_service", 0.0, _)
}

ChunkService::ChunkService() noexcept
    :mWorlds(Game::World::Blocks::getInstance()), mAuthority(true) {}
