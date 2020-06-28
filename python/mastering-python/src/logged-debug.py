# In The Name Of God
# ========================================
# [] File Name : logged-debug.py
#
# [] Creation Date : 13-12-2016
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
import pprint
import inspect
import logging
import functools

logging.basicConfig(level=logging.DEBUG)


def debug(function):
    @functools.wraps(function)
    def _debug(*args, **kwargs):
        try:
            result = function(*args, **kwargs)
        finally:
            # Extract the signarture from the function
            signature = inspect.signature(function)
            # Fill the arguments
            arguments = signature.bind(*args, **kwargs)
            arguments.apply_defaults()

            logging.debug('%s(%s): %s' % (function.__qualname__,
                                          ', '.join('%s=%r' % (k, v)
                                                    for k, v in
                                                    arguments.arguments.items()
                                                    ),
                                          pprint.pformat(result)
                                          ))
    return _debug


@debug
def spam(a, b=123):
    return 'some spam'

spam(1)
spam(1, 456)
spam(b=1, a=456)
