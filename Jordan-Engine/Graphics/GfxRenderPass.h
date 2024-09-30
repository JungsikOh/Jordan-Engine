#pragma once

#include "GfxCore.h"

// VULKAN INFO
// Attachment vs Attachment Reference
// Attachment: ������ ���� ����� ���ҽ�(��, colour, depth, stencil, etc)�� �����ϴ� ����ü.
//			�������� ���� �̹����� �Ӽ��� �����ϰ� ���⿡�� format, number of sample, loadOp, storeOp, inital/final layout
// Attachment Reference: Ư�� Subpass���� � Attachment�� �������� �����ϴ� ����ü.
//						Attachment�� �̹����� �Ӽ��� �����ϴ� �ݸ�, Ref�� �����н� ������ �̷��� Attachment�� ��� ���(�б�/����)�Ǵ����� ����.

struct AttachmentDesc
{
	VkFormat format;
	VkAttachmentLoadOp loadOp;
	VkClearValue clearValue;

	bool operator <(const AttachmentDesc& other) const
	{
		return std::tie(format, loadOp, clearValue) <
			std::tie(other.format, other.loadOp, other.clearValue);
	}
};

class GfxSubpass
{
public:
	GfxSubpass() = default;
	~GfxSubpass() = default;

	GfxSubpass& AddColorAttachment(AttachmentDesc colorAttchment);
	GfxSubpass& AddInputReference(VkImageLayout layout);
	GfxSubpass& SetDepthStencilAttachment(AttachmentDesc colorAttchment);

private:
	std::vector<AttachmentDesc> colorAttachmentDescs;
	std::vector<VkAttachmentReference> inputReferences;
	AttachmentDesc depthStencilAttachmentDesc;
};

class GfxRenderPass
{

	GfxRenderPass() = default;
	~GfxRenderPass() = default;

	void Initialize(VkDevice newDevice, std::vector<AttachmentDesc> colorAttchments, AttachmentDesc depthAttachment);
	void Destroy();

	void AddSubpass();

private:
	VkDevice device;

	VkRenderPass renderPass;
	std::vector<GfxSubpass> subpasses;
};

