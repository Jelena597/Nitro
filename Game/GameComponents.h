#pragma once

namespace Nitro
{
	enum class PlayerTag
	{
		One = 1,
		Two = 2
	};

	inline int
	PlayerTagToInt(PlayerTag p)
	{
		return static_cast<int>(p);
	}

	inline PlayerTag
	PlayerTagFromInt(int p)
	{
		ASSERT(p == 1 || p == 2, "int PLayerTag value must be 1 or 2");
		return static_cast<PlayerTag>(p);
	}

	
	
	struct PlayerTagComponent : public Engine::Component
	{
		PlayerTag m_PlayerTag;
		explicit PlayerTagComponent(PlayerTag playerTag_)
			: m_PlayerTag(playerTag_)
		{
		}
	};

	
}