#include "PCH.h"
#include "ResourcesMgr.h"


ResourcesMgr::ResourcesMgr()
{
}


ResourcesMgr::~ResourcesMgr()
{
}

Texture * ResourcesMgr::LoadTextureFromFile(const std::wstring & filename)
{
	if (!TextureMap.count(filename)) //텍스쳐맵에 이미 입력한 이름의 텍스쳐가 있는지 확인
	{
		auto texture = Texture::Create(filename);

		if (texture == nullptr)
			return nullptr;

		//텍스쳐맵에 이름과 텍스쳐를 매칭해 저장
		TextureMap[filename] = texture;
	}

	//이미 있으면 텍스쳐맵에서 꺼내서 반환
	return TextureMap[filename];

}
