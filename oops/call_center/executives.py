from call_center_enum import *

class Executive:
    '''
        Executive Class
    '''
    def __init__(self, name : str, number : int, designation : EmployeeType):
        self.__name = name
        self.__number = number
        self.__designation = designation
        self.__is_free = True
    
    def get_name(self) -> str: 
        '''
            Function for returning the name of the person
        '''
        return self.__name

    def set_name(self, name : str):
        '''
            function for setting the name of the employee
        '''
        self.__name = name

    def get_number(self):
        '''
            Function for returning the employee number
        '''
        return self.__number

    def set_number(self, number):
        '''
            Function for setting the employee number
        '''
        self.__number = number

    def get_designation(self):
        '''
            Function for returning the designation of an employee
        '''
        
        return self.__designation

    def set_designation(self, designation):
        '''
            Function for setting the designation of an employee
        '''
        self.__designation = designation

    def get_is_free(self):
        '''
            Function for getting if the employee is free or no
        '''
        return self.__is_free

    def set_is_free(self, is_free):
        '''
            Function for setting if the employee status
        '''
        self.__is_free = is_free

class Respondent(Executive):
    '''
        Respondent Class
    '''
    def __init__(self, name, number):
        Executive.__init__(self, name, number, EmployeeType.RESPONDENT)

class Manager(Executive):
    '''
        Manager Class
    '''
    def __init__(self, name, number):
        Executive.__init__(self, name, number, EmployeeType.MANAGER)

class Director(Executive):
    '''
        Director Class
    '''
    def __init__(self, name, number):
        Executive.__init__(self, name, number, EmployeeType.DIRECTOR)


class ExecutiveFactory:
    '''
        Factory for creating the appropriate executives
    '''
    def __init__(self):
        pass

    def create_executive(self, name, number, employee_type : EmployeeType):
        '''
            Function for creating the employee executvies
        '''
        if employee_type == EmployeeType.RESPONDENT:
            return Respondent(name, number)

        elif employee_type == EmployeeType.MANAGER:
            return Manager(name, number)

        elif employee_type == EmployeeType.DIRECTOR:
            return Director(name, number)

        else:
            return None