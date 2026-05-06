# def ft_count_harvest_recursive(num, i):
#    print(i)
#    if i < num:
#        ft_count_harvest_recursive(num, i + 1)
#    else:
#        print("Harvest time!")


# num = int(input("Days until harvest: "))
# i = 1


def ft_count_harvest_recursive():
    num = int(input("Days until harvest: "))

    def ft_helper(i):
        if i > num:
            print("Harvest time!")
            return
        print(f"Day {i}")
        ft_helper(i + 1)

    ft_helper(1)
