/** @file morpho-demo.hpp

    Copyright 2015 J.A. / http://www.tsdconseil.fr

    Project web page: http://www.tsdconseil.fr/log/opencv/demo/index-en.html

    This file is part of OCVDemo.

    OCVDemo is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OCVDemo is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with OCVDemo.  If not, see <http://www.gnu.org/licenses/>.
 **/

#ifndef MORPHO_DEMO_HPP_
#define MORPHO_DEMO_HPP_

#include "ocvdemo-item.hpp"

class MorphoDemo: public OCVDemoItem
{
public:
  MorphoDemo();
  int proceed(OCVDemoItemInput &input, OCVDemoItemOutput &output);
};

class DemoSqueletisation: public OCVDemoItem
{
public:
  DemoSqueletisation();
  int proceed(OCVDemoItemInput &input, OCVDemoItemOutput &output);
};

#endif /* MORPHO_DEMO_HPP_ */
