#include "mu_test.h"
#include "simulation.hpp"
#include "resourceManager.hpp"
#include "designRes.hpp"
#include "game.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <string>
#include <climits>


BEGIN_TEST(is_working)

    DesignRes ds;
    Game g(ResourceManager::instance(),ds);
    g.run();
    //Simulation s(ds);
    //s.run();
	ASSERT_THAT(true);
END_TEST


TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
    TEST(is_working)
END_SUITE

