#pragma once

#if SDC_VULKAN
#include <vulkan/vulkan.h>
#include <string>
#include "Rendering/RenderTypes.hpp"
#include "stb_image.hpp"

namespace GI::detail{
    class VKTextureHandle {
    public:
        VKTextureHandle() : textureImage(VK_NULL_HANDLE), textureImageMemory(VK_NULL_HANDLE), textureImageView(VK_NULL_HANDLE), textureSampler(VK_NULL_HANDLE) {};
        ~VKTextureHandle() { destroy();};

        static VKTextureHandle* create(std::string filename, u32 magFilter, u32 minFilter, bool repeat, bool flip);
        void bind();
        void destroy();

        uint32_t id;
    private:
        VkImage textureImage;
        VkDeviceMemory textureImageMemory;
        VkImageView textureImageView;
        VkSampler textureSampler;
    };
}
#endif