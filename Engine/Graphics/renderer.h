//
// Created by lukas on 14.11.21.
//

#ifndef VENDOR_RENDERER_H
#define VENDOR_RENDERER_H

#include "device.h"
#include "swap_chain.h"
#include "../Core/Window.h"

// std
#include <cassert>
#include <memory>
#include <vector>

namespace Engine {
    class Renderer {
    public:
        Renderer(Window &window, Device &device);
        ~Renderer();

        Renderer(const Renderer &) = delete;
        Renderer &operator=(const Renderer &) = delete;

        VkRenderPass getSwapChainRenderPass() const { return lveSwapChain->getRenderPass(); }
        uint32_t getImageCount() const { return lveSwapChain->imageCount(); }
        float getAspectRatio() const { return lveSwapChain->extentAspectRatio(); }
        bool isFrameInProgress() const { return isFrameStarted; }

        VkCommandBuffer getCurrentCommandBuffer() const {
            assert(isFrameStarted && "Cannot get command buffer when frame not in progress");
            return commandBuffers[currentFrameIndex];
        }

        int getFrameIndex() const {
            assert(isFrameStarted && "Cannot get frame index when frame not in progress");
            return currentFrameIndex;
        }

        VkCommandBuffer beginFrame();
        void endFrame();
        void beginSwapChainRenderPass(VkCommandBuffer commandBuffer);
        void endSwapChainRenderPass(VkCommandBuffer commandBuffer);

    private:
        void createCommandBuffers();
        void freeCommandBuffers();
        void recreateSwapChain();

        Window &lveWindow;
        Device &lveDevice;
        std::unique_ptr<SwapChain> lveSwapChain;
        std::vector<VkCommandBuffer> commandBuffers;

        uint32_t currentImageIndex;
        int currentFrameIndex{0};
        bool isFrameStarted{false};
    };
}


#endif //VENDOR_RENDERER_H
