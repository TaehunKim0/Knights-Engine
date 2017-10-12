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
	if (!TextureMap.count(filename)) //�ؽ��ĸʿ� �̹� �Է��� �̸��� �ؽ��İ� �ִ��� Ȯ��
	{
		auto texture = Texture::Create(filename);

		if (texture == nullptr)
			return nullptr;

		//�ؽ��ĸʿ� �̸��� �ؽ��ĸ� ��Ī�� ����
		TextureMap[filename] = texture;
	}

	//�̹� ������ �ؽ��ĸʿ��� ������ ��ȯ
	return TextureMap[filename];

}
