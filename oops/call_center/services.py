from executives import *
from interface import ExecutiveService, CallServiceInteface
from typing import List

class RespondentService(ExecutiveService):
    '''
        Respondent Service Class
    '''
    def __init__(self, respondents : List[Respondent]):
        self.__respondents = respondents

    def check_is_executive_free(self):
        '''
            Function which checks if a respondent is free or no
        '''
        for respondent in self.__respondents:
            if respondent.get_is_free():
                respondent.set_is_free(False)
                return respondent
        return None

class ManagerService(ExecutiveService):
    '''
        Manager Service Class
    '''
    def __init__(self, managers : List[Manager]):
        self.__managers = managers

    def check_is_executive_free(self):
        '''
            Function for checking if a manager is free or no
        '''
        for manager in self.__managers:
            if manager.get_is_free():
                manager.set_is_free(False)
                return manager
        return None

class DirectorService(ExecutiveService):
    '''
        Director Service
    '''
    def __init__(self, directors : List[Director]):
        self.__directors = directors

    def check_is_executive_free(self):
        '''
            Function for checking if a director is free or no
        '''
        for director in self.__directors:
            if director.get_is_free():
                director.set_is_free(False)
                return director
        return None

class ExecutiveServiceFactory:
    '''
        Executive Service Factory
    '''
    def __init__(self):
        pass

    def create_executive_services(self, executives : List, employee_type : EmployeeType):
        '''
            Function for creating executive services
        '''
        if employee_type == EmployeeType.DIRECTOR:
            return DirectorService(executives)
        elif employee_type == EmployeeType.MANAGER:
            return ManagerService(executives)
        if employee_type == EmployeeType.RESPONDENT:
            return RespondentService(executives)