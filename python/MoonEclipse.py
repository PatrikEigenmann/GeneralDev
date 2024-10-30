#!/bin/python
# ***************************************************************************************************************************
# moon_eclipse.py - The LunarEclipse class is a spectral entity, born from the cryptic dance of celestial bodies. It exists
# in the silent void, its essence woven from the fabric of the cosmos. Its purpose? To predict the eerie ballet of the
# Earth’s shadow as it engulfs the moon in darkness.
#
# Upon its summoning, it conjures an observer, a silent sentinel that stands vigil under the night sky. This observer, though
# bound by terrestrial chains, yearns for the mysteries that lie beyond our atmosphere.
#
# The method next_lunar_eclipse is the heart of this spectral entity. With each invocation, it reaches out to the moon,
# traversing the void of space, whispering to the lunar surface to reveal the time of the next eclipse.
#
# But beware, for the LunarEclipse class is a powerful entity. The cosmos is a vast, unpredictable place, and even the
# slightest miscalculation can lead to a dance of shadows at an unexpected time. Use this class with caution, for its power
# is as captivating as the lunar eclipse it predicts. Remember, when you gaze into the cosmos, the cosmos gazes back.
# ---------------------------------------------------------------------------------------------------------------------------
# Author:       Patrik Eigenmann
# eMail:        p.eigenmann@gmx.net
# ---------------------------------------------------------------------------------------------------------------------------
# Sat 2023-12-30 File created.                                                                                 Version: 00.01
# ***************************************************************************************************************************

import ephem

class LunarEclipse:
    def __init__(self):
        self.observer = ephem.Observer()

    def next_lunar_eclipse(self, city):
        self.observer.city = city
        next_eclipse = ephem.next_lunar_eclipse(self.observer.date)
        return next_eclipse

# Usage
eclipse = LunarEclipse()
print(eclipse.next_lunar_eclipse("San Francisco"))