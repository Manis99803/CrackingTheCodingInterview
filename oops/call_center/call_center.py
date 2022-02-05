'''
    Call Center: Imagine you have a call center with three levels of employees: respondent, manager and director. An incoming telephone call must be first allocated
    to a respondent who is free. If the respondent can't handle the call, he or she must escalate the call to a manager. If the manager is not fre or on table to handle it, 
    then the call should be esclated to a director. Design the classes and data structure for this problem. Implement a method dispatchCall() which assigns a class to 
    the first available employee
'''

'''
    Classes -> Respondent, Manager, Director

    Incoming call -> Respodent -> Manager -> Director

    - dispatchCall() function for dispatching the call
'''

from abc import ABC
from typing import List
from call_center_enum import *
from interface import *
from services import *
from call import Call


class CallCenter:
    '''
        Function which creates CallCentre
    '''
    def __init__(self, executives : List[Executive]):
        self.__executives : List[Executive] = executives

    def add_executives(self, executives : Executive):
        '''
            Function for adding the executives to the list
        '''
        self.__executives.append(executives)

    def get_executives(self):
        '''
            Function for getting the list of executives
        '''
        return self.__executives

class CallService(CallServiceInteface):
    '''
        Call Service Class
    '''
    def __init__(self, call_center : CallCenter):
        self.__call_center = call_center

    def __get_executive_for_the_call(self):
        '''
            Function for getting the executive which is free for picking up the call
        '''
        executive_categories : List[List[Executive]] = self.__call_center.get_executives()
        for executive_category in executive_categories:
            for executive in executive_category:
                if executive.get_is_free():
                    return executive

        return None

    def dispatch_call(self, call : Call):
        '''
            Function for assigning call to corresponding executives
        '''
        executive = self.__get_executive_for_the_call()
        if executive is not None:
            executive.set_is_free(False)
            call.set_call_attender(executive)
        
        return executive


executive_factory = ExecutiveFactory()

respondent_1 = executive_factory.create_executive("Manish", 12345, EmployeeType.RESPONDENT)
respondent_2 = executive_factory.create_executive("Soni", 67890, EmployeeType.RESPONDENT)

respondents = [respondent_1, respondent_2]

manager_1 = executive_factory.create_executive("Manish", 12345, EmployeeType.MANAGER)
manager_2 = executive_factory.create_executive("Soni", 67890, EmployeeType.MANAGER)

managers = [manager_1, manager_2]

director_1 = executive_factory.create_executive("Manish", 12345, EmployeeType.DIRECTOR)
director_2 = executive_factory.create_executive("Soni", 67890, EmployeeType.DIRECTOR)

directors = [director_1, director_2]

call_center = CallCenter([respondents, managers, directors])


call_0 = Call("12345")
call_service = CallService(call_center)
call_service.dispatch_call(call_0)
call_attender = call_0.get_call_attender()
print(call_attender.get_designation())

call_1 = Call("12345")
call_service.dispatch_call(call_1)
calL_attender = call_1.get_call_attender()
print(call_attender.get_designation())

call_2 = Call("12345")
call_service.dispatch_call(call_2)
call_attender = call_2.get_call_attender()
print(call_attender.get_designation())


call_3 = Call("12345")
call_service.dispatch_call(call_3)
call_attender = call_3.get_call_attender()
print(call_attender.get_designation())


call_4 = Call("12345")
call_service.dispatch_call(call_4)
call_attender = call_4.get_call_attender()
print(call_attender.get_designation())

call_5 = Call("12345")
call_service.dispatch_call(call_5)
call_attender = call_5.get_call_attender()
print(call_attender.get_designation())
