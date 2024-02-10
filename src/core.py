#!/usr/bin/python3

import ast
import src.transforms as transforms

from pathlib import Path

class Bettifier:

    @classmethod
    def activate(cls, file):
        """PERFORM EVERY STEP IN THE BETTIFICATION PROCESS"""
        file = Path(file)
        if (not file.exists()):
            raise FileNotFoundError()
        
        if len(tuple(cls.find_transformation_methods())) == 0:
            cls.bind_transformation_methods()

        cls.perform_transformations(file)

    
    @classmethod
    def perform_transformations(cls, file):
        """ONCE WE'VE DONE THE SANITY CHECKS RUN IT THROGUH GAUNTLET"""
        code = file.read_text()

        linting_process = cls.find_transformation_methods()

        for step in linting_process:
            code = step(code)

        file.write_text(code)


    @classmethod
    def is_transformation_method(cls, obj):
        """DEFINES FUNCTIONS THAT CAN BE DETATCHED AS STANDALONE SCRIPTS"""
        return (
            ('staticmethod' in str(obj.__class__)) and
            ("_" in obj.__name__)
        )


    @classmethod
    def find_transformation_methods(cls):
        """CREATES A GENERATOR WITH THE 'CORE' FUNCTIONS"""
        return (
            obj for obj in vars(cls).values()
                if (cls.is_transformation_method(obj))
        )


    @classmethod
    def bind_transformation_methods(cls):
        """BINDS EXTERNALLY DEFINED TEXT TRANSFORMS AS STATICMETHODS"""
        for x in transforms.methods:
            method_name = (f"_{x.__name__}")
            if (method_name in vars(cls)):
                continue

            setattr(cls, method_name, staticmethod(x))

        del transforms.methods


if (__name__ == "__main__"):
    """FOR USE IN INTERATIVE MODE"""
    import argparse

    parser = argparse.ArgumentParser(
        description=Bettifier.activate.__doc__
    )
    parser.add_argument("input_files", nargs="*", type=str)

    input_files = (
        Path(f) for f in (
            parser.parse_args().input_files
        )
    )
    for file in input_files:
        if (
            (file.exists()) and
            (file.suffix in (".c", ".h"))
        ):
            Bettifier.activate(file)
