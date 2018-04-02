import random

x = 5
s = 1

def get_random_note():
    return random.randint(1, 7)


def _get_sequence2():
    """Generate a sequence using a global variable."""
    global s
    r = s
    s = s + 1
    return r


class MakeGetSequence(object):
    """Make a sequence function using callable object."""
    def __init__(self):
        self.curr = 1

    def __call__(self):
        ret = self.curr
        self.curr += 1
        return ret


def MakeGetSequenceV2():
    """Make a sequence function using a non-local variable and function closure."""
    n = 1

    def func():
        nonlocal n
        r = n
        n += 1
        return r

    return func


_get_sequence1 = MakeGetSequence()
_get_sequence3 = MakeGetSequenceV2()

get_sequence = _get_sequence1
