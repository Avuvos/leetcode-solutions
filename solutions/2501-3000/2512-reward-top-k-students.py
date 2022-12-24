class Solution:
    def topStudents(self, positive_feedback: List[str], negative_feedback: List[str], report: List[str], student_id: List[int], k: int) -> List[int]:
        pos = set(positive_feedback)
        neg = set(negative_feedback)
        comb = []
        for i, s in enumerate(report):
            lst = s.split(" ")
            curr_student_res = 0
            for word in lst:
                if word in pos:
                    curr_student_res += 3
                if word in neg:
                    curr_student_res -= 1
            comb.append((curr_student_res, student_id[i]))
        comb = sorted(comb, key = lambda x: (-x[0], x[1]))
        res = [x[1] for x in comb[0:k]]
        return res
                    
