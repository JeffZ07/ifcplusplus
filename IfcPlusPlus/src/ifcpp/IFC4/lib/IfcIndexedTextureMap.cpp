/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4/include/IfcIndexedTextureMap.h"
#include "ifcpp/IFC4/include/IfcSurfaceTexture.h"
#include "ifcpp/IFC4/include/IfcTessellatedFaceSet.h"
#include "ifcpp/IFC4/include/IfcTextureVertexList.h"

// ENTITY IfcIndexedTextureMap 
IfcIndexedTextureMap::IfcIndexedTextureMap() {}
IfcIndexedTextureMap::IfcIndexedTextureMap( int id ) { m_entity_id = id; }
IfcIndexedTextureMap::~IfcIndexedTextureMap() {}
shared_ptr<BuildingObject> IfcIndexedTextureMap::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcIndexedTextureMap> copy_self( new IfcIndexedTextureMap() );
	for( size_t ii=0; ii<m_Maps.size(); ++ii )
	{
		auto item_ii = m_Maps[ii];
		if( item_ii )
		{
			copy_self->m_Maps.push_back( dynamic_pointer_cast<IfcSurfaceTexture>(item_ii->getDeepCopy(options) ) );
		}
	}
	if( m_MappedTo ) { copy_self->m_MappedTo = dynamic_pointer_cast<IfcTessellatedFaceSet>( m_MappedTo->getDeepCopy(options) ); }
	if( m_TexCoords ) { copy_self->m_TexCoords = dynamic_pointer_cast<IfcTextureVertexList>( m_TexCoords->getDeepCopy(options) ); }
	return copy_self;
}
void IfcIndexedTextureMap::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_entity_id << "= IFCINDEXEDTEXTUREMAP" << "(";
	writeEntityList( stream, m_Maps );
	stream << ",";
	if( m_MappedTo ) { stream << "#" << m_MappedTo->m_entity_id; } else { stream << "$"; }
	stream << ",";
	if( m_TexCoords ) { stream << "#" << m_TexCoords->m_entity_id; } else { stream << "$"; }
	stream << ");";
}
void IfcIndexedTextureMap::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_entity_id; }
const std::wstring IfcIndexedTextureMap::toString() const { return L"IfcIndexedTextureMap"; }
void IfcIndexedTextureMap::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<BuildingEntity> >& map )
{
	const size_t num_args = args.size();
	if( num_args != 3 ){ std::stringstream err; err << "Wrong parameter count for entity IfcIndexedTextureMap, expecting 3, having " << num_args << ". Entity ID: " << m_entity_id << std::endl; throw BuildingException( err.str().c_str() ); }
	readEntityReferenceList( args[0], m_Maps, map );
	readEntityReference( args[1], m_MappedTo, map );
	readEntityReference( args[2], m_TexCoords, map );
}
void IfcIndexedTextureMap::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes )
{
	IfcTextureCoordinate::getAttributes( vec_attributes );
	vec_attributes.push_back( std::make_pair( "MappedTo", m_MappedTo ) );
	vec_attributes.push_back( std::make_pair( "TexCoords", m_TexCoords ) );
}
void IfcIndexedTextureMap::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse )
{
	IfcTextureCoordinate::getAttributesInverse( vec_attributes_inverse );
}
void IfcIndexedTextureMap::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcTextureCoordinate::setInverseCounterparts( ptr_self_entity );
	shared_ptr<IfcIndexedTextureMap> ptr_self = dynamic_pointer_cast<IfcIndexedTextureMap>( ptr_self_entity );
	if( !ptr_self ) { throw BuildingException( "IfcIndexedTextureMap::setInverseCounterparts: type mismatch" ); }
	if( m_MappedTo )
	{
		m_MappedTo->m_HasTextures_inverse.push_back( ptr_self );
	}
}
void IfcIndexedTextureMap::unlinkFromInverseCounterparts()
{
	IfcTextureCoordinate::unlinkFromInverseCounterparts();
	if( m_MappedTo )
	{
		std::vector<weak_ptr<IfcIndexedTextureMap> >& HasTextures_inverse = m_MappedTo->m_HasTextures_inverse;
		for( auto it_HasTextures_inverse = HasTextures_inverse.begin(); it_HasTextures_inverse != HasTextures_inverse.end(); )
		{
			weak_ptr<IfcIndexedTextureMap> self_candidate_weak = *it_HasTextures_inverse;
			if( self_candidate_weak.expired() )
			{
				++it_HasTextures_inverse;
				continue;
			}
			shared_ptr<IfcIndexedTextureMap> self_candidate( *it_HasTextures_inverse );
			if( self_candidate.get() == this )
			{
				it_HasTextures_inverse= HasTextures_inverse.erase( it_HasTextures_inverse );
			}
			else
			{
				++it_HasTextures_inverse;
			}
		}
	}
}
