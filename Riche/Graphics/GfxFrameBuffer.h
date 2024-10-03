#pragma once
#include "GfxCore.h"

//class GfxRenderPass;
class GfxImage;

class GfxFrameBuffer
{
public:
	void Initialize(GfxRenderPass* newRenderPass, std::vector<GfxImage*>& newAttachments);
	void Destroy();

private:
	/*VkDevice device;*/	// ����� GfxRenderPass�� ����� VkDevice �̿�.

	VkFramebuffer framebuffer = VK_NULL_HANDLE;
	GfxRenderPass* renderPass;
	std::vector<GfxImage*> attachments;

	uint32_t width;
	uint32_t height;
};

