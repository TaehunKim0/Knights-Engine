#pragma once

#define SAFE_DELETE(x) { if(x) { delete x; x = NULL; } }
#define SAFE_RELEASE(x) { if(x) { x->Release(); x = NULL; } }

#define WIN32_LEAN_AND_MEAN //자주 사용하지 않는 api 정리

#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>
#include<string>

#include<vector>
#include<math.h>
#include<unordered_map>

#include"TypeDefine.h"
#include"Singleton.h"
#include"Application.h"
#include"Renderer.h"
#include"GameObject.h"
#include"Scene.h"
#include"Director.h"
#include"Texture.h"
#include"ResourcesMgr.h"
#include"Sprite.h"
#include"Animation.h"