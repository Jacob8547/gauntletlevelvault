#include <Geode/Geode.hpp>
#include <Geode/modify/GauntletLayer.hpp>
#include <Geode/modify/LevelBrowserLayer.hpp>

using namespace geode::prelude;

class $modify(MyLevelBrowserLayer, LevelBrowserLayer)
{
};

class $modify(MyGauntletLayer, GauntletLayer)
{

	bool init(GauntletType p0)
	{
		if (!GauntletLayer::init(p0))
		{
			return false;
		};

		if (p0 == GauntletType::Fire)
		{
			auto firelogo = CCSprite::createWithSpriteFrameName("island_fire_001.png");
			firelogo->setScale(0.5);

			auto firebutton = CCMenuItemSpriteExtra::create(
				firelogo,
				this,
				menu_selector(MyGauntletLayer::fire));

			firebutton->setPosition({16.25, 60.25});
			firebutton->setZOrder(5);
			firebutton->setID("fire-levels"_spr);

			auto menu = GauntletLayer::getChildByID("exit-menu");
			menu->addChild(firebutton);

			GauntletLayer::updateLayout();

			return true;
		}
		else if (p0 == GauntletType::Ice)
		{
			auto icelogo = CCSprite::createWithSpriteFrameName("island_ice_001.png");
			icelogo->setScale(0.5);

			auto icebutton = CCMenuItemSpriteExtra::create(
				icelogo,
				this,
				menu_selector(MyGauntletLayer::ice));

			icebutton->setPosition({16.25, 60.25});
			icebutton->setZOrder(5);
			icebutton->setID("ice-levels"_spr);

			auto menu = GauntletLayer::getChildByID("exit-menu");
			menu->addChild(icebutton);

			GauntletLayer::updateLayout();

			return true;
		}
		else if (p0 == GauntletType::Poison)
		{
			auto poisonlogo = CCSprite::createWithSpriteFrameName("island_poison_001.png");
			poisonlogo->setScale(0.5);

			auto poisonbutton = CCMenuItemSpriteExtra::create(
				poisonlogo,
				this,
				menu_selector(MyGauntletLayer::poison));

			poisonbutton->setPosition({16.25, 60.25});
			poisonbutton->setZOrder(5);
			poisonbutton->setID("poison-levels"_spr);

			auto menu = GauntletLayer::getChildByID("exit-menu");
			menu->addChild(poisonbutton);

			GauntletLayer::updateLayout();

			return true;
		}
		else if (p0 == GauntletType::Shadow)
		{
			auto shadowlogo = CCSprite::createWithSpriteFrameName("island_shadow_001.png");
			shadowlogo->setScale(0.5);

			auto shadowbutton = CCMenuItemSpriteExtra::create(
				shadowlogo,
				this,
				menu_selector(MyGauntletLayer::shadow));

			shadowbutton->setPosition({16.25, 60.25});
			shadowbutton->setZOrder(5);
			shadowbutton->setID("shadow-levels"_spr);

			auto menu = GauntletLayer::getChildByID("exit-menu");
			menu->addChild(shadowbutton);

			GauntletLayer::updateLayout();

			return true;
		}
		else if (p0 == GauntletType::Lava)
		{
			auto lavalogo = CCSprite::createWithSpriteFrameName("island_lava_001.png");
			lavalogo->setScale(0.5);

			auto lavabutton = CCMenuItemSpriteExtra::create(
				lavalogo,
				this,
				menu_selector(MyGauntletLayer::lava));

			lavabutton->setPosition({16.25, 60.25});
			lavabutton->setZOrder(5);
			lavabutton->setID("lava-levels"_spr);

			auto menu = GauntletLayer::getChildByID("exit-menu");
			menu->addChild(lavabutton);

			GauntletLayer::updateLayout();

			return true;
		}
		else if (p0 == GauntletType::Bonus)
		{
			auto bonuslogo = CCSprite::createWithSpriteFrameName("island_bonus_001.png");
			bonuslogo->setScale(0.5);

			auto bonusbutton = CCMenuItemSpriteExtra::create(
				bonuslogo,
				this,
				menu_selector(MyGauntletLayer::bonus));

			bonusbutton->setPosition({16.25, 60.25});
			bonusbutton->setZOrder(5);
			bonusbutton->setID("bonus-levels"_spr);

			auto menu = GauntletLayer::getChildByID("exit-menu");
			menu->addChild(bonusbutton);

			GauntletLayer::updateLayout();

			return true;
		}
		else if (p0 == GauntletType::Chaos)
		{
			auto chaoslogo = CCSprite::createWithSpriteFrameName("island_chaos_001.png");
			chaoslogo->setScale(0.5);

			auto chaosbutton = CCMenuItemSpriteExtra::create(
				chaoslogo,
				this,
				menu_selector(MyGauntletLayer::chaos));

			chaosbutton->setPosition({16.25, 60.25});
			chaosbutton->setZOrder(5);
			chaosbutton->setID("chaos-levels"_spr);

			auto menu = GauntletLayer::getChildByID("exit-menu");
			menu->addChild(chaosbutton);

			GauntletLayer::updateLayout();

			return true;
		}
		else if (p0 == GauntletType::Demon)
		{
			auto demonlogo = CCSprite::createWithSpriteFrameName("island_demon_001.png");
			demonlogo->setScale(0.5);

			auto demonbutton = CCMenuItemSpriteExtra::create(
				demonlogo,
				this,
				menu_selector(MyGauntletLayer::demon));

			demonbutton->setPosition({16.25, 60.25});
			demonbutton->setZOrder(5);
			demonbutton->setID("demon-levels"_spr);

			auto menu = GauntletLayer::getChildByID("exit-menu");
			menu->addChild(demonbutton);

			GauntletLayer::updateLayout();

			return true;
		}
		else if (p0 == GauntletType::Time)
		{
			auto timelogo = CCSprite::createWithSpriteFrameName("island_time_001.png");
			timelogo->setScale(0.5);

			auto timebutton = CCMenuItemSpriteExtra::create(
				timelogo,
				this,
				menu_selector(MyGauntletLayer::time));

			timebutton->setPosition({16.25, 60.25});
			timebutton->setZOrder(5);
			timebutton->setID("time-levels"_spr);

			auto menu = GauntletLayer::getChildByID("exit-menu");
			menu->addChild(timebutton);

			GauntletLayer::updateLayout();

			return true;
		}
		else if (p0 == GauntletType::Crystal)
		{
			auto crystallogo = CCSprite::createWithSpriteFrameName("island_crystal_001.png");
			crystallogo->setScale(0.5);

			auto crystalbutton = CCMenuItemSpriteExtra::create(
				crystallogo,
				this,
				menu_selector(MyGauntletLayer::crystal));

			crystalbutton->setPosition({16.25, 60.25});
			crystalbutton->setZOrder(5);
			crystalbutton->setID("crystal-levels"_spr);

			auto menu = GauntletLayer::getChildByID("exit-menu");
			menu->addChild(crystalbutton);

			GauntletLayer::updateLayout();

			return true;
		}
		else if (p0 == GauntletType::Magic)
		{
			auto magiclogo = CCSprite::createWithSpriteFrameName("island_magic_001.png");
			magiclogo->setScale(0.5);

			auto magicbutton = CCMenuItemSpriteExtra::create(
				magiclogo,
				this,
				menu_selector(MyGauntletLayer::magic));

			magicbutton->setPosition({16.25, 60.25});
			magicbutton->setZOrder(5);
			magicbutton->setID("magic-levels"_spr);

			auto menu = GauntletLayer::getChildByID("exit-menu");
			menu->addChild(magicbutton);

			GauntletLayer::updateLayout();

			return true;
		}
		else if (p0 == GauntletType::Spike)
		{
			auto spikelogo = CCSprite::createWithSpriteFrameName("island_spike_001.png");
			spikelogo->setScale(0.5);

			auto spikebutton = CCMenuItemSpriteExtra::create(
				spikelogo,
				this,
				menu_selector(MyGauntletLayer::spike));

			spikebutton->setPosition({16.25, 60.25});
			spikebutton->setZOrder(5);
			spikebutton->setID("spike-levels"_spr);

			auto menu = GauntletLayer::getChildByID("exit-menu");
			menu->addChild(spikebutton);

			GauntletLayer::updateLayout();

			return true;
		}
		else if (p0 == GauntletType::Monster)
		{
			auto monsterlogo = CCSprite::createWithSpriteFrameName("island_monster_001.png");
			monsterlogo->setScale(0.5);

			auto monsterbutton = CCMenuItemSpriteExtra::create(
				monsterlogo,
				this,
				menu_selector(MyGauntletLayer::monster));

			monsterbutton->setPosition({16.25, 60.25});
			monsterbutton->setZOrder(5);
			monsterbutton->setID("monster-levels"_spr);

			auto menu = GauntletLayer::getChildByID("exit-menu");
			menu->addChild(monsterbutton);

			GauntletLayer::updateLayout();

			return true;
		}
		else if (p0 == GauntletType::Doom)
		{
			auto doomlogo = CCSprite::createWithSpriteFrameName("island_doom_001.png");
			doomlogo->setScale(0.5);

			auto doombutton = CCMenuItemSpriteExtra::create(
				doomlogo,
				this,
				menu_selector(MyGauntletLayer::doom));

			doombutton->setPosition({16.25, 60.25});
			doombutton->setZOrder(5);
			doombutton->setID("doom-levels"_spr);

			auto menu = GauntletLayer::getChildByID("exit-menu");
			menu->addChild(doombutton);

			GauntletLayer::updateLayout();

			return true;
		}
		else if (p0 == GauntletType::Death)
		{
			auto deathlogo = CCSprite::createWithSpriteFrameName("island_death_001.png");
			deathlogo->setScale(0.5);

			auto deathbutton = CCMenuItemSpriteExtra::create(
				deathlogo,
				this,
				menu_selector(MyGauntletLayer::death));

			deathbutton->setPosition({16.25, 60.25});
			deathbutton->setZOrder(5);
			deathbutton->setID("death-levels"_spr);

			auto menu = GauntletLayer::getChildByID("exit-menu");
			menu->addChild(deathbutton);

			GauntletLayer::updateLayout();

			return true;
		}
	}

	// Functions
	void fire(CCObject *obj)
	{
		std::list<int> list = {27732941, 28200611, 27483789, 28225110, 27448202};
		std::ostringstream query;

		for (int number : list)
		{
			query << number;
			query << ",";
		}

		auto searchObject = GJSearchObject::create(SearchType::Type19, query.str());
		auto browserLayer = static_cast<MyLevelBrowserLayer *>(LevelBrowserLayer::create(searchObject));
		auto scene = CCScene::create();
		scene->addChild(browserLayer);
		auto trans = CCTransitionFade::create(0.5, scene);
		CCDirector::sharedDirector()->pushScene(trans);
	}

	void ice(CCObject *obj)
	{
		std::list<int> list = {20635816, 28151870, 25969464, 24302376, 27399722};
		std::ostringstream query;

		for (int number : list)
		{
			query << number;
			query << ",";
		}

		auto searchObject = GJSearchObject::create(SearchType::Type19, query.str());
		auto browserLayer = static_cast<MyLevelBrowserLayer *>(LevelBrowserLayer::create(searchObject));
		auto scene = CCScene::create();
		scene->addChild(browserLayer);
		auto trans = CCTransitionFade::create(0.5, scene);
		CCDirector::sharedDirector()->pushScene(trans);
	}

	void poison(CCObject *obj)
	{
		std::list<int> list = {28179535, 29094196, 29071134, 26317634, 12107595};
		std::ostringstream query;

		for (int number : list)
		{
			query << number;
			query << ",";
		}

		auto searchObject = GJSearchObject::create(SearchType::Type19, query.str());
		auto browserLayer = static_cast<MyLevelBrowserLayer *>(LevelBrowserLayer::create(searchObject));
		auto scene = CCScene::create();
		scene->addChild(browserLayer);
		auto trans = CCTransitionFade::create(0.5, scene);
		CCDirector::sharedDirector()->pushScene(trans);
	}

	void shadow(CCObject *obj)
	{
		std::list<int> list = {26949498, 26095850, 27973097, 27694897, 26070995};
		std::ostringstream query;

		for (int number : list)
		{
			query << number;
			query << ",";
		}

		auto searchObject = GJSearchObject::create(SearchType::Type19, query.str());
		auto browserLayer = static_cast<MyLevelBrowserLayer *>(LevelBrowserLayer::create(searchObject));
		auto scene = CCScene::create();
		scene->addChild(browserLayer);
		auto trans = CCTransitionFade::create(0.5, scene);
		CCDirector::sharedDirector()->pushScene(trans);
	}

	void lava(CCObject *obj)
	{
		std::list<int> list = {18533341, 28794068, 28127292, 4243988, 28677296};
		std::ostringstream query;

		for (int number : list)
		{
			query << number;
			query << ",";
		}

		auto searchObject = GJSearchObject::create(SearchType::Type19, query.str());
		auto browserLayer = static_cast<MyLevelBrowserLayer *>(LevelBrowserLayer::create(searchObject));
		auto scene = CCScene::create();
		scene->addChild(browserLayer);
		auto trans = CCTransitionFade::create(0.5, scene);
		CCDirector::sharedDirector()->pushScene(trans);
	}

	void bonus(CCObject *obj)
	{
		std::list<int> list = {28255647, 27929950, 16437345, 28270854, 29394058};
		std::ostringstream query;

		for (int number : list)
		{
			query << number;
			query << ",";
		}

		auto searchObject = GJSearchObject::create(SearchType::Type19, query.str());
		auto browserLayer = static_cast<MyLevelBrowserLayer *>(LevelBrowserLayer::create(searchObject));
		auto scene = CCScene::create();
		scene->addChild(browserLayer);
		auto trans = CCTransitionFade::create(0.5, scene);
		CCDirector::sharedDirector()->pushScene(trans);
	}

	void chaos(CCObject *obj)
	{
		std::list<int> list = {25886024, 4259126, 26897899, 7485599, 19862531};
		std::ostringstream query;

		for (int number : list)
		{
			query << number;
			query << ",";
		}

		auto searchObject = GJSearchObject::create(SearchType::Type19, query.str());
		auto browserLayer = static_cast<MyLevelBrowserLayer *>(LevelBrowserLayer::create(searchObject));
		auto scene = CCScene::create();
		scene->addChild(browserLayer);
		auto trans = CCTransitionFade::create(0.5, scene);
		CCDirector::sharedDirector()->pushScene(trans);
	}

	void demon(CCObject *obj)
	{
		std::list<int> list = {18025697, 23189196, 27786218, 27728679, 25706351};
		std::ostringstream query;

		for (int number : list)
		{
			query << number;
			query << ",";
		}

		auto searchObject = GJSearchObject::create(SearchType::Type19, query.str());
		auto browserLayer = static_cast<MyLevelBrowserLayer *>(LevelBrowserLayer::create(searchObject));
		auto scene = CCScene::create();
		scene->addChild(browserLayer);
		auto trans = CCTransitionFade::create(0.5, scene);
		CCDirector::sharedDirector()->pushScene(trans);
	}

	void time(CCObject *obj)
	{
		std::list<int> list = {40638411, 32614529, 31037168, 40937291, 35165900};
		std::ostringstream query;

		for (int number : list)
		{
			query << number;
			query << ",";
		}

		auto searchObject = GJSearchObject::create(SearchType::Type19, query.str());
		auto browserLayer = static_cast<MyLevelBrowserLayer *>(LevelBrowserLayer::create(searchObject));
		auto scene = CCScene::create();
		scene->addChild(browserLayer);
		auto trans = CCTransitionFade::create(0.5, scene);
		CCDirector::sharedDirector()->pushScene(trans);
	}

	void crystal(CCObject *obj)
	{
		std::list<int> list = {37188385, 35280911, 37187779, 36301959, 36792656};
		std::ostringstream query;

		for (int number : list)
		{
			query << number;
			query << ",";
		}

		auto searchObject = GJSearchObject::create(SearchType::Type19, query.str());
		auto browserLayer = static_cast<MyLevelBrowserLayer *>(LevelBrowserLayer::create(searchObject));
		auto scene = CCScene::create();
		scene->addChild(browserLayer);
		auto trans = CCTransitionFade::create(0.5, scene);
		CCDirector::sharedDirector()->pushScene(trans);
	}

	void magic(CCObject *obj)
	{
		std::list<int> list = {37269362, 29416734, 36997718, 39853981, 39853458};
		std::ostringstream query;

		for (int number : list)
		{
			query << number;
			query << ",";
		}

		auto searchObject = GJSearchObject::create(SearchType::Type19, query.str());
		auto browserLayer = static_cast<MyLevelBrowserLayer *>(LevelBrowserLayer::create(searchObject));
		auto scene = CCScene::create();
		scene->addChild(browserLayer);
		auto trans = CCTransitionFade::create(0.5, scene);
		CCDirector::sharedDirector()->pushScene(trans);
	}

	void spike(CCObject *obj)
	{
		std::list<int> list = {27873500, 34194741, 34851342, 36500807, 39749578};
		std::ostringstream query;

		for (int number : list)
		{
			query << number;
			query << ",";
		}

		auto searchObject = GJSearchObject::create(SearchType::Type19, query.str());
		auto browserLayer = static_cast<MyLevelBrowserLayer *>(LevelBrowserLayer::create(searchObject));
		auto scene = CCScene::create();
		scene->addChild(browserLayer);
		auto trans = CCTransitionFade::create(0.5, scene);
		CCDirector::sharedDirector()->pushScene(trans);
	}

	void monster(CCObject *obj)
	{
		std::list<int> list = {43908596, 41736289, 42843431, 44063088, 44131636};
		std::ostringstream query;

		for (int number : list)
		{
			query << number;
			query << ",";
		}

		auto searchObject = GJSearchObject::create(SearchType::Type19, query.str());
		auto browserLayer = static_cast<MyLevelBrowserLayer *>(LevelBrowserLayer::create(searchObject));
		auto scene = CCScene::create();
		scene->addChild(browserLayer);
		auto trans = CCTransitionFade::create(0.5, scene);
		CCDirector::sharedDirector()->pushScene(trans);
	}

	void doom(CCObject *obj)
	{
		std::list<int> list = {38427291, 38514054, 36966088, 38398923, 36745142};
		std::ostringstream query;

		for (int number : list)
		{
			query << number;
			query << ",";
		}

		auto searchObject = GJSearchObject::create(SearchType::Type19, query.str());
		auto browserLayer = static_cast<MyLevelBrowserLayer *>(LevelBrowserLayer::create(searchObject));
		auto scene = CCScene::create();
		scene->addChild(browserLayer);
		auto trans = CCTransitionFade::create(0.5, scene);
		CCDirector::sharedDirector()->pushScene(trans);
	}

	void death(CCObject *obj)
	{
		std::list<int> list = {44121158, 43923301, 43537990, 33244195, 35418014};
		std::ostringstream query;

		for (int number : list)
		{
			query << number;
			query << ",";
		}

		auto searchObject = GJSearchObject::create(SearchType::Type19, query.str());
		auto browserLayer = static_cast<MyLevelBrowserLayer *>(LevelBrowserLayer::create(searchObject));
		auto scene = CCScene::create();
		scene->addChild(browserLayer);
		auto trans = CCTransitionFade::create(0.5, scene);
		CCDirector::sharedDirector()->pushScene(trans);
	}
};