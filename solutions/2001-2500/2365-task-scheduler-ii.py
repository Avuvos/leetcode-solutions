class Solution:
    def taskSchedulerII(self, tasks: List[int], space: int) -> int:
        last = defaultdict(int) #task into last day did the task
        if len(tasks) == 1: return 1
        day = 0
        for task in tasks:
            last_day = last[task]
            if last_day == 0:
                day += 1
                last[task] = day
                continue
            else:
                diff = day - last_day
                extra = max(0, space - diff)
                last[task] = day + extra + 1
                day += extra
                day += 1
        return day
            
