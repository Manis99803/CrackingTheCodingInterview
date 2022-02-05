from executives import Executive

class Call:
    def __init__(self, call_id : str):
        self.__call_id : str = call_id
        self.__call_attender : Executive = None 

    def get_call_id(self) -> str:
        '''
            Function for returning the call id of a call
        '''
        return self.__call_id

    def set_call_id(self, call_id : str):
        '''
            Function for setting the call id
        '''
        self.__call_id = call_id

    def set_call_attender(self, call_attender : Executive):
        '''
            Function for setting the call attender
        '''
        self.__call_attender = call_attender

    def get_call_attender(self):
        '''
            Function for getting the call attender name
        '''
        return self.__call_attender