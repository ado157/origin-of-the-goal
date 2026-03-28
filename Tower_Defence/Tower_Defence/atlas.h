#pragma once
#include<SDL.h>
#include<SDL_image.h>

#include<string>
#include<vector>
#include<memory>

struct AtlasTextureDeleter
{
	void operator()(SDL_Texture* texture) const
	{
		if (texture)
			SDL_DestroyTexture(texture);
	}
};

class Atlas
{
public:
	Atlas() = default;
  ~Atlas() = default;

	void load(SDL_Renderer* renderer, const char* path_template, int num)
	{
		for (int i = 0; i < num; i++)
		{
			char path_file[256];
			sprintf_s(path_file,path_template, i+1);
            tex_list.emplace_back(IMG_LoadTexture(renderer, path_file));
		}
	}
	void clear()
	{
		tex_list.clear();
	}

	int get_size() const
	{
		return (int)tex_list.size();
	}

	SDL_Texture* get_texture(int idx)
	{
		if (idx < 0 || idx >=tex_list.size())
			return nullptr;
       return tex_list[idx].get();
	}
	void add_texture(SDL_Texture* texture)
	{
        tex_list.emplace_back(texture);
	}

private:
 std::vector<std::unique_ptr<SDL_Texture, AtlasTextureDeleter>> tex_list;

};
