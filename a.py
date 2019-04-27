def func():
    def nested():
        global x
        x = 1
    x = 3
    nested()
    print("func:",x)

x = 2
func()
print("main:",x)
