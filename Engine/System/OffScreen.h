//
// Created by lukas on 27.11.21.
//

#ifndef ENGINEEDITOR_OFFSCREEN_H
#define ENGINEEDITOR_OFFSCREEN_H

#include <vulkan/vulkan.h>
#include "../Graphics/Device.h"
#include "pipeline.h"
#include "../pgepch.h"
#include "../Graphics/FrameInfo.h"
#include "../Graphics/Core.h"

namespace Engine {

    struct FrameBufferAttachment {
        VkImage image;
        VkDeviceMemory mem;
        VkImageView view;
    };

    class OffScreen {
    public:
        OffScreen(uint32_t width, uint32_t height);
        //void Init(Device device);
        ~OffScreen();

        VkSampler GetSampler() { return sampler; }
        VkImageView GetImageView() { return color.view; }
        VkRenderPass GetRenderPass() { return renderPass; }
        void SetViewportSize(const glm::vec2& size) {
            m_Width = size.x;
            m_Height = size.y;

            CreateImages();
        }

        void Start(FrameInfo frameInfo);
        void End(FrameInfo frameInfo);
    private:
        void CreateImages();

        uint32_t m_Width, m_Height;
        VkFramebuffer frameBuffer;
        FrameBufferAttachment color, depth;
        VkRenderPass renderPass;
        VkSampler sampler;
        VkDescriptorImageInfo descriptor;
    };
}


#endif //ENGINEEDITOR_OFFSCREEN_H