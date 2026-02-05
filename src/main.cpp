#include <Geode/Geode.hpp>
#include <Geode/modify/GauntletLayer.hpp>

using namespace geode::prelude;

// Modifies each GauntletLayer (Fire,Random,Ice,etc.)
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

		// Create the button icon based on the gauntlet the player is on.
		auto gauntletlogo = CCSprite::createWithSpriteFrameName(GauntletNode::frameForType(p0).c_str());
		gauntletlogo->setScale(0.5);

		// Create the button (logo, class_modified, function_when_clicked).
		auto gauntletbutton = CCMenuItemSpriteExtra::create(
			gauntletlogo,
			this,
			menu_selector(MyGauntletLayer::gauntlet));

		// Set the id of the button.
		gauntletbutton->setID("gauntlet-levels"_spr);

		// Add button to the menu.
		auto menu = GauntletLayer::getChildByID("exit-menu");
		menu->addChild(gauntletbutton);

		// Update the menu to show button.
		menu->updateLayout();

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

#include <Geode/modify/GauntletSelectLayer.hpp>

class $modify(MyGauntletSelectLayer, GauntletSelectLayer)
{
	bool init(int p0)
	{
		if (!GauntletSelectLayer::init(p0))
		{
			return false;
		}

		auto icon = CCSprite::createWithSpriteFrameName("island_new01_001.png");
		icon->setScale(0.45);

		auto buttonsprite = CircleButtonSprite::create(icon, CircleBaseColor::Green, CircleBaseSize::Medium);

		auto alllevelsbutton = CCMenuItemSpriteExtra::create(
			buttonsprite,
			this,
			menu_selector(MyGauntletSelectLayer::gauntlet));

		alllevelsbutton->setID("all-gauntlet-levels"_spr);

		auto menu = GauntletSelectLayer::getChildByID("top-right-menu");
		menu->addChild(alllevelsbutton);

		menu->updateLayout();

		return true;
	}

	void gauntlet(CCObject *obj)
	{
		// Creates and displays a text box.
		FLAlertLayer::create(
			"Gauntlet Level Vault",
			"<cj>Enter a gauntlet! There is a button near the top that lets you play the levels!</c>",
			"OK")
			->show();
	}
};
