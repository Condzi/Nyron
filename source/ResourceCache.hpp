#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

#include "Logger.hpp"

namespace cn
{
	template<class T>
	class ResourceCache final
	{
	public:
		ResourceCache();
		~ResourceCache() = default;

		void load(const std::vector<std::string>& paths)
		{
			T* temporaryResource;
			std::pair<std::uint16_t, std::uint16_t> loadedResourcesCount{ 0,paths.size() };

			for (auto& path : paths)
			{
				temporaryResource = new T;

				if (temporaryResource->loadFromFile(path))
				{
					Logger::log("Added new resource '" + path + "'", Logger::PREFIX_INFO);

					resources[path].reset(temporaryResource);
					++loadedResourcesCount.first;

					continue;
				}

				delete temporaryResource;
				Logger::log("Unable to load resource  '" + path + "'", Logger::PREFIX_ERROR);
			}

			Logger::log("Loaded " + std::to_string(loadedResourcesCount.first) + "/" + std::to_string(loadedResourcesCount.second) + " resources", Logger::PREFIX_INFO);
		}

		T* get(const std::string& name);
	
	private:
		std::unordered_map<std::string, std::unique_ptr<T>> resources;
	};

	template<class T>
	inline ResourceCache<T>::ResourceCache()
	{
	}

	template<class T>
	inline T* ResourceCache<T>::get(const std::string & name)
	{
		auto result = resources.find(name);
		
		if (result != resources.end())
			return resources[name].get();
			
		Logger::log("Cannot return resource '" + name + "'", Logger::PREFIX_ERROR);

		return nullptr;
	}
}