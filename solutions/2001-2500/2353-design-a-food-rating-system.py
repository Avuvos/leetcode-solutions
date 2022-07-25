from sortedcontainers import SortedList

class FoodRatings:

    #map cusine -> list of foods with that cusine sorted by their rank then food name
    #map food -> index so we can get its cusine and ratings quickly

    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.ratings = ratings
        self.cusines = cuisines
        self.food_to_index = defaultdict(int)
        self.cusine_to_rating = defaultdict(SortedList)
        
        for index, (food, cusine, rating) in enumerate(zip(foods, cuisines, ratings)):
            self.food_to_index[food] = index
            self.cusine_to_rating[cusine].add((-rating, food))

    def changeRating(self, food: str, newRating: int) -> None:
        index = self.food_to_index[food]
        cusine = self.cusines[index]
        self.cusine_to_rating[cusine].discard((-self.ratings[index], food))
        self.cusine_to_rating[cusine].add((-newRating, food))
        self.ratings[index] = newRating

    def highestRated(self, cuisine: str) -> str:
        return self.cusine_to_rating[cuisine][0][1]

# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)
