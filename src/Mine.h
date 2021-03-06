#pragma once

#include "Common.h"
#include "Constants.h"

#include "NAS2D/Xml/XmlElement.h"

#include <bitset>

/**
 * 
 */
class Mine
{
public:
	enum OreType
	{
		ORE_COMMON_METALS,
		ORE_COMMON_MINERALS,
		ORE_RARE_METALS,
		ORE_RARE_MINERALS,
	};

	typedef std::array<int, 4> MineVein;
	typedef std::vector<MineVein> MineVeins;	/**<  */

public:
	Mine();
	Mine(MineProductionRate rate);
	~Mine() {};

	bool active() const;
	void active(bool _b);

	bool exhausted() const;
	void checkExhausted();

	MineProductionRate productionRate() { return mProductionRate; }

	int depth() const;
	void increaseDepth();

	int commonMetalsAvailable() const;
	int commonMineralsAvailable() const;
	int rareMetalsAvailable() const;
	int rareMineralsAvailable() const;

	bool miningCommonMetals() const;
	bool miningCommonMinerals() const;
	bool miningRareMetals() const;
	bool miningRareMinerals() const;

	void miningCommonMetals(bool _b);
	void miningCommonMinerals(bool _b);
	void miningRareMetals(bool _b);
	void miningRareMinerals(bool _b);

	int pull(OreType type, int quantity);

public:
	void serialize(NAS2D::Xml::XmlElement* _ti);
	void deserialize(NAS2D::Xml::XmlElement* _ti);

private:
	Mine(const Mine&) = delete;
	Mine& operator=(const Mine&) = delete;

private:
	MineVeins			mVeins;									/**< Ore veins */
	MineProductionRate	mProductionRate = PRODUCTION_RATE_LOW;	/**< Mine's production rate. */
	
	/**
	 * Flags indicating several states for the mine:
	 * 
	 * [0] : Mine Common Metal Ore
	 * [1] : Mine Common Mineral Ore
	 * [2] : Mine Rare Metal Ore
	 * [3] : Mine Rare Mineral Ore
	 * [4] : Mine is active
	 * [5] : Mine is exhausted
	 */
	std::bitset<6>		mFlags;									/**< Set of flags. */
};
