# You can generate a FFANN that complies with the convensions of sadET in a simple way
#Run python GenerateFFANN.py > FFANN.hpp and then make, to see that it really works
from uuid import uuid4


class GenerateFFANN:
    def __init__(self, N_inputs, N_outputs, hiddenNodes, activationFunctions):

        self.total_layers=2+len(hiddenNodes) #total layers = No. layers + input layer + output layer
        N=self.total_layers#define this for convinience here

        #an array to hold number of nodes at each layer
        self.nodes=[N_inputs]
        for _n in hiddenNodes:
            self.nodes.append(_n)
        self.nodes.append(N_outputs)
        #declare the signals
        #in case you get confused, these are the indices
        self.inputs=[ 'x[{0}]'.format(i) for i in range(N_inputs)]
        self.outputs=[ 'y[{0}]'.format(i) for i in range(N_outputs)]
        
        self.signals=[ ['s{0}{1}'.format(l,j) for j in range(self.nodes[l])]  for l in range(N)]
        self.Templates=[ ['sadET::Variable<numericType>' for j in range(self.nodes[l])]  for l in range(N)]
        for i in range(N_inputs):
            self.signals[0][i]=self.inputs[i]
        
            
        #in case you get confused, these are the indices
        self.weights=[ [['0' for i in range(self.nodes[l])] for j in range(self.nodes[l+1])]  for l in range(N-1)]
        
                    
                
        #in case you get confused, these are the indices
        self.biases=[ ['0' for j in range(self.nodes[l+1])]  for l in range(self.total_layers-1)]    
        
        self.activations=activationFunctions
       
        self.replace_names()
        
        self.feedForward()
        self.Types()
        self.Templates=self.Templates[-1]
        
        self.outputsF=self.signals[-1][:]
    
        
            
    def replace_names(self):
        s=0
        for l in range(self.total_layers-1):
            for j in range(self.nodes[l+1]):
                for i in range(self.nodes[l]):
                    self.weights[l][j][i]='w[{}]'.format(s)
                    s+=1
        self.N_weights=s

        s=0
        for l in range(self.total_layers-1):
            for j in range(self.nodes[l+1]):
                self.biases[l][j]='b[{}]'.format(s)
                s+=1
        self.N_biases=s


                    
    def print(self):
        print(self.inputs)
        print(self.outputs)
        print(self.outputsF)

    def sum_wx(self,l,j):
        _ = ''
        for i,_sum in enumerate([ self.weights[l-1][j][i]+ ' * ' + xi  for i,xi in enumerate(self.signals[l-1]) ]):
            if i == 0:
                _=_sum
            else:
                _+=' + '+_sum

        return _ + ' + ' + self.biases[l-1][j]

    def calcSignal(self, l,j):
        
        self.signals[l][j] =  '{0}( {1} )'.format( self.activations[l-1], self.sum_wx(l,j))
    
    def feedForward(self):
        for l in range(1,self.total_layers):
            for j in range(self.nodes[l]):
                self.calcSignal(l,j)
                

                
    def Tsum_wx(self,l,j):
        _ = ''
        for i,_sum in enumerate([ 'sadET::Multiplication< sadET::Variable<numericType> , {} >'.format(xi)  for i,xi in enumerate(self.Templates[l-1]) ]):
            if i == 0:
                _=_sum
            else:
                _='sadET::Addition< {} , {} >'.format(_,_sum,)
                
        return 'sadET::Addition<{},sadET::Variable<numericType>>'.format(_)

    def TcalcSignal(self, l,j):
        if self.activations[l-1] == '':
            self.Templates[l][j] =  '{0}'.format(self.Tsum_wx(l,j))
        else:
            self.Templates[l][j] =  '{0}< {1} >'.format( self.activations[l-1], self.Tsum_wx(l,j))

    def Types(self):
        for l in range(1,self.total_layers):
            for j in range(self.nodes[l]):
                self.TcalcSignal(l,j)#all outputs have the same type!

            
    def printCpp(self,class_name,namespace):
        var='sadET::Variable<numericType>'
        
        guard_macro = 'FFANN_{}_INCLUDED'.format( str(uuid4()).upper().replace('-','') )
        print('#ifndef '+guard_macro)
        print('#define '+guard_macro)  
        print('#include<vector>')
        print('#include<sadET.hpp>\n')
        
        print('namespace {}'.format(namespace)+'{\n')

        print('template<typename numericType>')
        print('class {}'.format(class_name)+'{')
        
        print('')
        print('\tstd::vector<{0}> w,b;'.format(var))
        print('')
        
        print('\tpublic:')
        
        print('\tusing outputType={};'.format(self.Templates[0]))
        print('')
        print('\t~{}()=default;'.format(class_name))

        print('')
        
        print('\t{0}(const std::vector<{1}> &w, const std::vector<{1}> &b):w(w),b(b)'.format(class_name,var)+'{};')
            
        print('\tvoid biases(const std::vector<numericType> &b){for(unsigned int i;i<NumberOfBiasess;++i){this->b[i].evaluate()=b[i];}};')
        print('\tvoid weights(const std::vector<numericType> &w){for(unsigned int i;i<NumberOfWeights;++i){this->w[i].evaluate()=w[i];}};')
        print('')

        print('\tconstexpr static size_t NumberOfInputs = {};'.format(self.nodes[0]))
        print('\tconstexpr static size_t NumberOfOutputs = {};'.format(self.nodes[-1]))
        print('\tconstexpr static size_t NumberOfWeights = {};'.format(self.N_weights))
        print('\tconstexpr static size_t NumberOfBiasess = {};'.format(self.N_biases))
        print('')
        
        print('\tstd::vector<{}>& biases()'.format(var)+'{return b;}') 
        print('\tstd::vector<{}>& weights()'.format(var)+'{return w;}') 
        
        print('\tauto operator()(const std::vector<{}> &x)'.format(var)+'{')
        print('\t\tstd::vector<outputType> y={')
        
        for i,y in enumerate(self.outputsF):
            if i==self.nodes[-1]-1:
                _='\n'
            else:
                _=',\n'
            print('\t\t\t{}'.format(y),end=_)
        
        
        print('\t\t};')
        
        print('\t\treturn y;\n\t};')
        
        print('')
        print('};\n')
        print('};\n')
        print('')
        print('#endif')



def main():
    brain=GenerateFFANN(1,1,[1],['sadET::Exp','',''])
    brain.printCpp('FFAANN','ann')

if __name__=='__main__':
    main()
