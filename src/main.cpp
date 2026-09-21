#include <Geode/Geode.hpp>
#include <Geode/modify/GauntletLayer.hpp>

using namespace geode::prelude;

// Modifies each GauntletLayer (Fire, Random, Ice, etc.)
class $modify(MyGauntletLayer, GauntletLayer)
{
	// If player is on screen, continue.
	bool init(GauntletType p0)
	{
		// If player is not on screen, return.
		if (!GauntletLayer::init(p0))
		{
			return false;
		};

		// Create a director (used for menu placement).
		auto director = CCDirector::sharedDirector();

		// Create the button icon based on the gauntlet the player is on.
		auto gauntletlogo = CCSprite::createWithSpriteFrameName("GJ_safeBtn_001.png");

		// Create the button (logo, class_modified, function_when_clicked).
		auto gauntletbutton = CCMenuItemSpriteExtra::create(
			gauntletlogo,
			this,
			menu_selector(MyGauntletLayer::gauntlet));

		// Set the id of the button.
		gauntletbutton->setID("gauntlet-levels"_spr);

		// Create new menu on right side.
		auto rightMenu = CCMenu::create();
		rightMenu->setID("gauntlet-levels-menu"_spr);
		rightMenu->setContentSize({32.5f, 125.f});
		rightMenu->ignoreAnchorPointForPosition(false);
		rightMenu->setAnchorPoint({0.5f, 0.5f});
		rightMenu->setPosition({director->getScreenRight() - 25.f,
								director->getScreenTop() - 64.25f});

		// Set button positioning. Add button to the menu.
		gauntletbutton->setPosition({rightMenu->getContentSize().width / 2,
									 rightMenu->getContentSize().height - gauntletbutton->getContentSize().height / 2});
		rightMenu->addChild(gauntletbutton);

		// Create a container to put menu/button in. (It crashes without it).
		auto container = CCNode::create();
		container->setID("gauntlet-levels-container"_spr);
		container->addChild(rightMenu);
		this->addChild(container);

		return true;
	}

	void gauntlet(CCObject *obj)
	{
		// Get all gauntlets available.
		auto gauntlets = GameLevelManager::sharedState()->m_savedGauntlets;
		// Gets the gauntlet for the screen the player is on.
		// m_gauntletType is enum which is converted to int which is converted to string.
		auto gauntlet = static_cast<GJMapPack *>(gauntlets->objectForKey(std::to_string(static_cast<int>(m_gauntletType))));
		// Creates the "search screen" with all levels in that gauntlet.
		auto searchObject = GJSearchObject::create(SearchType::Type19, gauntlet->m_levelStrings);
		// Creates actual UI for screen.
		auto browserLayer = LevelBrowserLayer::create(searchObject);
		// Creates scene to be displayed.
		auto scene = CCScene::create();
		// Adds UI to scene.
		scene->addChild(browserLayer);
		// Declares transition time to push scene.
		auto trans = CCTransitionFade::create(0.5, scene);
		// Displays scene.
		CCDirector::sharedDirector()->pushScene(trans);
	}
};