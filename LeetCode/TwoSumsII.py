class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        mydict = {}
        index = 0

        for num in numbers:
            need = target - num

            if need in mydict:
                return [mydict[need] + 1, index + 1]
            else:
                mydict.update({num : index})
                index += 1