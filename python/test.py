from functools import wraps
 
def logit(func):
    @wraps(func)
    def with_logging(*args, **kwargs):
        print(func.__name__ + " was called")
        return func(*args, **kwargs)
    return with_logging
 
@logit
def addition_func(x):
   """Do some math."""
   return x + x
 
 
result = addition_func(4)
print(result)
# Output: addition_func was called


# ##########################################################
# def wrap(f):
#     def decorator(*args, **kw):
#         print('Call %s()' % f.__name__)
#         return f(*args, **kw)
    
#     print('wrap return-->')
#     return decorator
 
# @wrap
# def func(a, b):
#     return a * 10 + b
 
# if __name__ == '__main__':
#     print(func(1, 2))


# ########################################################
# def wrap1(f):
#     def decorator(*args, **kw):
#         print('Call %s() in wrap1' % f.__name__)
#         return f(*args, **kw)
#     print('wrap1 return-->')
#     return decorator
 
 
# def wrap2(f):
#     def decorator(*args, **kw):
#         print('Call %s() in wrap2' % f.__name__)
#         return f(*args, **kw)
#     print('wrap2 return-->')
#     return decorator
 
 
# @wrap2
# @wrap1
# def func(a, b):
#     return a * 10 + b
 
 
# if __name__ == '__main__':
#     print(func(5, 6))

# wrap2(wrap1(func))

# wrap2 ->
#     warp1 -> 
#         >>> wrap1 return-->
#         return : decorator (f)
#     >>> wrap2 return-->
#     return decorator(decorator(f))

# decorator 
#     >> Call decorator() in wrap2
#     decorator 
#         >> Call func() in wrap1
#         f
#             >> 56
