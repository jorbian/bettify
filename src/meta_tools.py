#!/usr/bin/python3

import importlib

from pathlib import Path

class MetaToolbox:

    @staticmethod
    def get_module_functions(mod_file, filter=(lambda x: x == x)):
        """RETRIEVE FUNCTIONS DEFINED IN GLOBAL NAMESPACE OF MODULE"""
        mod_file = Path(mod_file)
        if ((not mod_file.exists()) or (mod_file.suffix != ".py")):
            return (iter(()))
        
        mod_name = mod_file.stem

        mod_obj = importlib.import_module(mod_name)

        return (
            obj for (id, obj) in vars(mod_obj).items()
                if (
                    (("__" not in id) and (callable(obj))) and filter(obj)
                )
        )
    
    @staticmethod
    def bind_method_to_class(cls_obj, func_obj, **options):
        """BIND FUNCTION OBJECT TO SPECIFIED CLASS"""
        for (option, toggle) in (
            {
                "is_static": (lambda x: staticmethod(x)),
                "is_class": (lambda x: classmethod(x)),
            }.items()
        ):
            if (options.get(option)):
                func_obj = toggle(func_obj)
                break

        setattr(cls_obj, func_obj.__name__, func_obj)

