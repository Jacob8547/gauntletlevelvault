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
		auto gauntlet = static_cast<GJMapPack*>(gauntlets->objectForKey(std::to_string(static_cast<int>(m_gauntletType))));
		auto searchObject = GJSearchObject::create(SearchType::Type19, gauntlet->m_levelStrings);
		auto browserLayer = LevelBrowserLayer::create(searchObject);
		auto scene = CCScene::create();
		scene->addChild(browserLayer);
		auto trans = CCTransitionFade::create(0.5, scene);
		CCDirector::sharedDirector()->pushScene(trans);
	}
};