import math
cups_desired = float(input())
oz_desired = 8 * cups_desired

#How much of a recipe is the desired cups? (1, double, half, etc.)
recipe_factor = cups_desired / 1.5

glue_needed  = 6 * float(recipe_factor)
water_needed = 4.5 * float(recipe_factor)
borax_needed = 0.25 * float(recipe_factor)

print("You need %0.1f" %glue_needed, "ounces of glue, %0.1f" %water_needed, "ounces of water, and %0.1f" %borax_needed, "ounces of borax.")
