#include <Geode/Geode.hpp>
#include <Geode/modify/GauntletLayer.hpp>

using namespace geode::prelude;

class $modify(MyGauntletLayer, GauntletLayer)
{

	bool init(GauntletType p0)
	{
		if (!GauntletLayer::init(p0))
		{
			return false;
		};

		auto gauntletlogo = CCSprite::createWithSpriteFrameName(GauntletNode::frameForType(p0).c_str());
		gauntletlogo->setScale(0.5);

		auto gauntletbutton = CCMenuItemSpriteExtra::create(
			gauntletlogo,
			this,
			menu_selector(MyGauntletLayer::gauntlet));

		gauntletbutton->setPosition({16.25, 60.25});
		gauntletbutton->setZOrder(5);
		gauntletbutton->setID("gauntlet-levels"_spr);

		auto menu = GauntletLayer::getChildByID("exit-menu");
		menu->addChild(gauntletbutton);

		GauntletLayer::updateLayout();

		return true;
	}

	void gauntlet(CCObject *obj)
	{
		auto gauntlets = GameLevelManager::sharedState()->m_savedGauntlets;
		auto gauntlet = static_cast<GJMapPack *>(gauntlets->objectForKey(std::to_string(static_cast<int>(m_gauntletType))));
		auto searchObject = GJSearchObject::create(SearchType::Type19, gauntlet->m_levelStrings);
		auto browserLayer = LevelBrowserLayer::create(searchObject);
		auto scene = CCScene::create();
		scene->addChild(browserLayer);
		auto trans = CCTransitionFade::create(0.5, scene);
		CCDirector::sharedDirector()->pushScene(trans);
	}
};

#include <Geode/modify/GauntletSelectLayer.hpp>

class $modify(MyGauntletSelectLayer, GauntletSelectLayer)
{
	bool init(int p0)
	{
		if (!GauntletSelectLayer::init(p0))
		{
			return false;
		}

		auto buttonsprite = CCSprite::createWithSpriteFrameName("geode.loader/baseCircle_Medium_Green.png");

		auto alllevelsbutton = CCMenuItemSpriteExtra::create(
			buttonsprite,
			this,
			menu_selector(MyGauntletSelectLayer::gauntlet));

		auto icon = CCSprite::createWithSpriteFrameName("island_new01_001.png");
		icon->setScale(0.45);

		icon->setPositionX(23.375);
		icon->setPositionY(24.5);
		buttonsprite->addChild(icon);
		alllevelsbutton->setPosition(30, 93);
		alllevelsbutton->setID("all-gauntlet-levels"_spr);

		auto menu = GauntletSelectLayer::getChildByID("top-right-menu");
		menu->addChild(alllevelsbutton);

		GauntletSelectLayer::updateLayout();

		return true;
	}

	void gauntlet(CCObject *obj)
	{
		FLAlertLayer::create(
			"Gauntlet Level Vault",
			"<cj>Enter a gauntlet! There is a button near the top that lets you play the levels!</c>",
			"OK")
			->show();

		// auto gauntlets = GameLevelManager::sharedState()->m_savedGauntlets;
		// gd::string levelstrings;
		// for (int i = 1; i <= 18; i++)
		// {

		// 	auto gauntlet = static_cast<GJMapPack *>(gauntlets->objectForKey(std::to_string(static_cast<int>(i))));
		// 	if (!gauntlet) {
		// 		continue;
		// 	}
		// 	levelstrings = levelstrings + gauntlet->m_levelStrings + ",";
		// }

		// auto searchObject = GJSearchObject::create(SearchType::Type19, levelstrings);
		// auto browserLayer = LevelBrowserLayer::create(searchObject);
		// auto scene = CCScene::create();
		// scene->addChild(browserLayer);
		// auto trans = CCTransitionFade::create(0.5, scene);
		// CCDirector::sharedDirector()->pushScene(trans);
	}
};
