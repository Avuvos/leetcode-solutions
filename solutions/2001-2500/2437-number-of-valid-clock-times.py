class Solution:
    def countTime(self, time: str) -> int:
        hours = 3
        if time[0] == '?':
            if time[1] == '?':
                hours = 3 * 8
            elif (int(time[1]) <= 5 and int(time[1]) > 3) or (int(time[1]) >= 4):
                hours -= 1
        elif time[1] == '?':
            if int(time[0]) == 2:
                hours = 4
            else:
                hours = 10
        else:
            hours = 1

        minutes = 1
        if time[3] == '?':
            minutes *= 6
        if time[4] == '?':
            minutes *= 10
        return hours * minutes
