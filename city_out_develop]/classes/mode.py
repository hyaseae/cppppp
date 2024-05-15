from enum import Enum
import enum
class Mode(Enum):
    WORK = enum.auto()
    REST = enum.auto()
    WAIT = enum.auto()
    MOVING = enum.auto()
    SLEEP = enum.auto()
    HURT = enum.auto()


    #place
    WORKPLACE = enum.auto()
    HOME = enum.auto()
    GREEN = enum.auto()
    HOSPITAL = enum.auto()
    DSETINATION = enum.auto()