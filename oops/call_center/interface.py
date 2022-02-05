from abc import ABC

class CallServiceInteface(ABC):
    '''
        Call Service 
    '''
    def dispatch_call(self):
        '''
            Functin for alloting the call executives
        '''
        pass


class ExecutiveService(ABC):
    '''
        Interface which will check if an executive is free or no
    '''
    def check_is_executive_free(self):
        pass

class CallCenterService(ABC):
    def add_executives(self):
        '''
            Function for adding the executives to the call centers
        '''
        pass

    def get_managers(self):
        '''
            Function for getting the list of managers
        '''
        pass

    def get_directors(self):
        '''
            Function for getting the list of directors
        '''
        pass

    def get_respondents(self):
        '''
            Function for getting the list of respondents
        '''
        pass