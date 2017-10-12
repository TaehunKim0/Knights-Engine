#pragma once
class ResourcesMgr : public Singleton<ResourcesMgr>
{
private:
	std::unordered_map<std::wstring, Texture*> TextureMap;

public:
	ResourcesMgr();
	~ResourcesMgr();

	Texture* LoadTextureFromFile(const std::wstring& filename);
};

