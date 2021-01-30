from Gaudi.Configuration import *

from Configurables import MCGeneratorStandAlone
producer = MCGeneratorStandAlone()
producer.PerEventPrintMessage = "Hello World !"
producer.MCGeneratorName = "Herwig"

from Configurables import ApplicationMgr
ApplicationMgr( TopAlg=[producer],
                EvtSel="NONE",
                EvtMax=1,                
                OutputLevel=INFO,
                )

