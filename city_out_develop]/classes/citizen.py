




class Cityzen:
    def __init__(self,homex,homey,workx,worky) -> None:
        #기본 수치
        self.physical_health = 100
        self.mental_health = 100
        self.money=100
        self.food = 100
        self.fatigue = 0
        self.sleepy = 0

        from mode import Mode
        self.mode = Mode.WAIT
        self.destination = Mode.DSETINATION
        self.workspace = (workx,worky)
        self.homespace = (homex,homey)



        #가중치
        from random import random
        self.physical_health_weight = random()
        self.mental_health_weight = random()
        self.money_weight=random()
        self.fatigue_weigth = random()
        self.food_weigth = random()
        self.sleepy_weigth = random()